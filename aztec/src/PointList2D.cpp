#include "PointList2D.h"
namespace Aztec {
  PointList2D::PointList2D()
  {
    _className.assign("PointList2D");
  }

  PointList2D::~PointList2D()
  {
  }

  void PointList2D::clear()
  {
    m_point_list.clear();
  }
  Vector2 PointList2D::add(float x, float y)
  {
    m_point_list.push_back(Vector2(x, y));
    return m_point_list.back();
  }

  Vector2 PointList2D::add(Vector2 v)
  {
    m_point_list.push_back(Vector2(v));
    return m_point_list.back();
  }

  Vector2 PointList2D::get(int idx)
  {

    if (idx < 0 || idx > m_point_list.size() - 1)
      return Vector2(-FLT_MAX, -FLT_MAX);
    return m_point_list[idx];
  }

  Vector2 PointList2D::set(int idx, float x, float y)
  {
    if (idx < 0 || idx > m_point_list.size() - 1)
      return Vector2(-FLT_MAX, -FLT_MAX);
    m_point_list[idx].set(x, y);
    return m_point_list[idx];
  }
  Vector2 PointList2D::set(int idx, Vector2 v)
  {
    if (idx < 0 || idx > m_point_list.size() - 1)
      return Vector2(-FLT_MAX, -FLT_MAX);
    m_point_list[idx].assign(v);
    return m_point_list[idx];
  }
  Vector2 PointList2D::remove(int idx)
  {
    if (idx < 0 || idx > m_point_list.size() - 1)
      return Vector2(-FLT_MAX, -FLT_MAX);
    Vector2 point = m_point_list[idx];
    m_point_list.erase(m_point_list.begin() + idx);
    return point;
  }

  vector<Vector2> PointList2D::getList()
  {
    return m_point_list;
  }
} // namespace Aztec