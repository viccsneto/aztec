#include "ContactSolver.h"
#include "ContactFilter.h"
#include "EventDispatcher.h"
#include "EventTypes.h"
#include "Sensor.h"

namespace Aztec {
  void ContactSolver::BeginContact(b2Contact *contact)
  {
    GameObject *a, *b;

    b2Fixture *fixtureA = contact->GetFixtureA();
    b2Fixture *fixtureB = contact->GetFixtureB();

    a = (GameObject *)fixtureA->GetBody()->GetUserData();
    b = (GameObject *)fixtureB->GetBody()->GetUserData();

    if (a == NULL || b == NULL) {
      return;
    }

    if (fixtureA->GetFilterData().categoryBits & ContactFilter::FilterFlags::Camera) //a camera
    {
      if (fixtureB->GetFilterData().categoryBits & ContactFilter::FilterFlags::Renderable) {

        b->insideCameraBounds = true;
      }
    }
    else if (fixtureB->GetFilterData().categoryBits & ContactFilter::FilterFlags::Camera) //b camera
    {
      if (fixtureA->GetFilterData().categoryBits & ContactFilter::FilterFlags::Renderable) {
        a->insideCameraBounds = true;
      }
    }
    else if (fixtureA->GetFilterData().categoryBits & ContactFilter::FilterFlags::Mouse) {
      if (fixtureB->GetFilterData().categoryBits & ContactFilter::FilterFlags::Sensor) {
        GameObject *target = ((Sensor *)b)->getTarget();
        if (target != NULL) {
          target->mouseOver = true;
        }
      }
      else if (fixtureB->GetFilterData().categoryBits & ContactFilter::FilterFlags::Text) {
        b->mouseOver = true;
      }
    }
    else if (fixtureB->GetFilterData().categoryBits & ContactFilter::FilterFlags::Mouse) {
      if (fixtureA->GetFilterData().categoryBits & ContactFilter::FilterFlags::Sensor) {
        GameObject *target = ((Sensor *)a)->getTarget();
        if (target != NULL) {
          target->mouseOver = true;
        }
      }
      else if (fixtureA->GetFilterData().categoryBits & ContactFilter::FilterFlags::Text) {
        a->mouseOver = true;
      }
    }
    else {
      EventDispatcher::doBeginContact(((Sensor *)a)->getTarget(), ((Sensor *)b)->getTarget());
      EventDispatcher::doBeginContact(((Sensor *)b)->getTarget(), ((Sensor *)a)->getTarget());
    }
  }

  void ContactSolver::EndContact(b2Contact *contact)
  {
    GameObject *a, *b;

    b2Fixture *fixtureA = contact->GetFixtureA();
    b2Fixture *fixtureB = contact->GetFixtureB();

    a = (GameObject *)fixtureA->GetBody()->GetUserData();
    b = (GameObject *)fixtureB->GetBody()->GetUserData();

    if (a == NULL || b == NULL) {
      return;
    }

    if (fixtureA->GetFilterData().categoryBits & ContactFilter::FilterFlags::Camera) //a camera
    {
      if (fixtureB->GetFilterData().categoryBits & ContactFilter::FilterFlags::Renderable) {
        if (b != NULL) {
          b->insideCameraBounds = false;
        }
      }
    }
    else if (fixtureB->GetFilterData().categoryBits & ContactFilter::FilterFlags::Camera) //b camera
    {
      if (fixtureA->GetFilterData().categoryBits & ContactFilter::FilterFlags::Renderable) {
        if (a != NULL) {
          a->insideCameraBounds = false;
        }
      }
    }
    else if (fixtureA->GetFilterData().categoryBits & ContactFilter::FilterFlags::Mouse) {
      if (fixtureB->GetFilterData().categoryBits & ContactFilter::FilterFlags::Sensor) {
        GameObject *target = ((Sensor *)b)->getTarget();
        if (target != NULL) {
          target->mouseOver = false;
        }
      }
      else if (fixtureB->GetFilterData().categoryBits & ContactFilter::FilterFlags::Text) {
        b->mouseOver = false;
      }
    }
    else if (fixtureB->GetFilterData().categoryBits & ContactFilter::FilterFlags::Mouse) {
      if (fixtureA->GetFilterData().categoryBits & ContactFilter::FilterFlags::Sensor) {
        GameObject *target = ((Sensor *)a)->getTarget();
        if (target != NULL) {
          target->mouseOver = false;
        }
      }
      else if (fixtureA->GetFilterData().categoryBits & ContactFilter::FilterFlags::Text) {
        a->mouseOver = false;
      }
    }
    else {
      EventDispatcher::doEndContact(((Sensor *)a)->getTarget(), ((Sensor *)b)->getTarget());
      EventDispatcher::doEndContact(((Sensor *)b)->getTarget(), ((Sensor *)a)->getTarget());
    }
  }

} // namespace Aztec
