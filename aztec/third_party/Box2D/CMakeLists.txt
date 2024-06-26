# CMake entry point
cmake_minimum_required (VERSION 3.0)
project (Box2D)

set (BOX2D_VERSION 2.0)

set(BOX2D_Collision_SRCS
	Box2D/Collision/b2BroadPhase.cpp
	Box2D/Collision/b2CollideCircle.cpp
	Box2D/Collision/b2CollideEdge.cpp
	Box2D/Collision/b2CollidePolygon.cpp
	Box2D/Collision/b2Collision.cpp
	Box2D/Collision/b2Distance.cpp
	Box2D/Collision/b2DynamicTree.cpp
	Box2D/Collision/b2TimeOfImpact.cpp
)
set(BOX2D_Collision_HDRS
	Box2D/Collision/b2BroadPhase.h
	Box2D/Collision/b2Collision.h
	Box2D/Collision/b2Distance.h
	Box2D/Collision/b2DynamicTree.h
	Box2D/Collision/b2TimeOfImpact.h
)
set(BOX2D_Shapes_SRCS
	Box2D/Collision/Shapes/b2CircleShape.cpp
	Box2D/Collision/Shapes/b2EdgeShape.cpp
	Box2D/Collision/Shapes/b2ChainShape.cpp
	Box2D/Collision/Shapes/b2PolygonShape.cpp
)
set(BOX2D_Shapes_HDRS
	Box2D/Collision/Shapes/b2CircleShape.h
	Box2D/Collision/Shapes/b2EdgeShape.h
	Box2D/Collision/Shapes/b2ChainShape.h
	Box2D/Collision/Shapes/b2PolygonShape.h
	Box2D/Collision/Shapes/b2Shape.h
)
set(BOX2D_Common_SRCS
	Box2D/Common/b2BlockAllocator.cpp
	Box2D/Common/b2Draw.cpp
	Box2D/Common/b2Math.cpp
	Box2D/Common/b2Settings.cpp
	Box2D/Common/b2StackAllocator.cpp
	Box2D/Common/b2Timer.cpp
)
set(BOX2D_Common_HDRS
	Box2D/Common/b2BlockAllocator.h
	Box2D/Common/b2Draw.h
	Box2D/Common/b2GrowableStack.h
	Box2D/Common/b2Math.h
	Box2D/Common/b2Settings.h
	Box2D/Common/b2StackAllocator.h
	Box2D/Common/b2Timer.h
)
set(BOX2D_Dynamics_SRCS
	Box2D/Dynamics/b2Body.cpp
	Box2D/Dynamics/b2ContactManager.cpp
	Box2D/Dynamics/b2Fixture.cpp
	Box2D/Dynamics/b2Island.cpp
	Box2D/Dynamics/b2World.cpp
	Box2D/Dynamics/b2WorldCallbacks.cpp
)
set(BOX2D_Dynamics_HDRS
	Box2D/Dynamics/b2Body.h
	Box2D/Dynamics/b2ContactManager.h
	Box2D/Dynamics/b2Fixture.h
	Box2D/Dynamics/b2Island.h
	Box2D/Dynamics/b2TimeStep.h
	Box2D/Dynamics/b2World.h
	Box2D/Dynamics/b2WorldCallbacks.h
)
set(BOX2D_Contacts_SRCS
	Box2D/Dynamics/Contacts/b2CircleContact.cpp
	Box2D/Dynamics/Contacts/b2Contact.cpp
	Box2D/Dynamics/Contacts/b2ContactSolver.cpp
	Box2D/Dynamics/Contacts/b2PolygonAndCircleContact.cpp
	Box2D/Dynamics/Contacts/b2EdgeAndCircleContact.cpp
	Box2D/Dynamics/Contacts/b2EdgeAndPolygonContact.cpp
	Box2D/Dynamics/Contacts/b2ChainAndCircleContact.cpp
	Box2D/Dynamics/Contacts/b2ChainAndPolygonContact.cpp
	Box2D/Dynamics/Contacts/b2PolygonContact.cpp
)
set(BOX2D_Contacts_HDRS
	Box2D/Dynamics/Contacts/b2CircleContact.h
	Box2D/Dynamics/Contacts/b2Contact.h
	Box2D/Dynamics/Contacts/b2ContactSolver.h
	Box2D/Dynamics/Contacts/b2PolygonAndCircleContact.h
	Box2D/Dynamics/Contacts/b2EdgeAndCircleContact.h
	Box2D/Dynamics/Contacts/b2EdgeAndPolygonContact.h
	Box2D/Dynamics/Contacts/b2ChainAndCircleContact.h
	Box2D/Dynamics/Contacts/b2ChainAndPolygonContact.h
	Box2D/Dynamics/Contacts/b2PolygonContact.h
)
set(BOX2D_Joints_SRCS
	Box2D/Dynamics/Joints/b2DistanceJoint.cpp
	Box2D/Dynamics/Joints/b2FrictionJoint.cpp
	Box2D/Dynamics/Joints/b2GearJoint.cpp
	Box2D/Dynamics/Joints/b2Joint.cpp
	Box2D/Dynamics/Joints/b2MotorJoint.cpp
	Box2D/Dynamics/Joints/b2MouseJoint.cpp
	Box2D/Dynamics/Joints/b2PrismaticJoint.cpp
	Box2D/Dynamics/Joints/b2PulleyJoint.cpp
	Box2D/Dynamics/Joints/b2RevoluteJoint.cpp
	Box2D/Dynamics/Joints/b2RopeJoint.cpp
	Box2D/Dynamics/Joints/b2WeldJoint.cpp
	Box2D/Dynamics/Joints/b2WheelJoint.cpp
)
set(BOX2D_Joints_HDRS
	Box2D/Dynamics/Joints/b2DistanceJoint.h
	Box2D/Dynamics/Joints/b2FrictionJoint.h
	Box2D/Dynamics/Joints/b2GearJoint.h
	Box2D/Dynamics/Joints/b2Joint.h
	Box2D/Dynamics/Joints/b2MotorJoint.h
	Box2D/Dynamics/Joints/b2MouseJoint.h
	Box2D/Dynamics/Joints/b2PrismaticJoint.h
	Box2D/Dynamics/Joints/b2PulleyJoint.h
	Box2D/Dynamics/Joints/b2RevoluteJoint.h
	Box2D/Dynamics/Joints/b2RopeJoint.h
	Box2D/Dynamics/Joints/b2WeldJoint.h
	Box2D/Dynamics/Joints/b2WheelJoint.h
)
set(BOX2D_Rope_SRCS
	Box2D/Rope/b2Rope.cpp
)
set(BOX2D_Rope_HDRS
	Box2D/Rope/b2Rope.h
)
set(BOX2D_General_HDRS
	Box2D/Box2D.h
)
include_directories(../)

add_library(Box2D 
		${BOX2D_General_HDRS}
		${BOX2D_Joints_SRCS}
		${BOX2D_Joints_HDRS}
		${BOX2D_Contacts_SRCS}
		${BOX2D_Contacts_HDRS}
		${BOX2D_Dynamics_SRCS}
		${BOX2D_Dynamics_HDRS}
		${BOX2D_Common_SRCS}
		${BOX2D_Common_HDRS}
		${BOX2D_Shapes_SRCS}
		${BOX2D_Shapes_HDRS}
		${BOX2D_Collision_SRCS}
		${BOX2D_Collision_HDRS}
		${BOX2D_Rope_SRCS}
		${BOX2D_Rope_HDRS}
)

set_target_properties(Box2D PROPERTIES
  OUTPUT_NAME "Box2D"
	CLEAN_DIRECT_OUTPUT 1
	VERSION ${BOX2D_VERSION}
)



# These are used to create visual studio folders.
source_group(Collision FILES ${BOX2D_Collision_SRCS} ${BOX2D_Collision_HDRS})
source_group(Collision\\Shapes FILES ${BOX2D_Shapes_SRCS} ${BOX2D_Shapes_HDRS})
source_group(Common FILES ${BOX2D_Common_SRCS} ${BOX2D_Common_HDRS})
source_group(Dynamics FILES ${BOX2D_Dynamics_SRCS} ${BOX2D_Dynamics_HDRS})
source_group(Dynamics\\Contacts FILES ${BOX2D_Contacts_SRCS} ${BOX2D_Contacts_HDRS})
source_group(Dynamics\\Joints FILES ${BOX2D_Joints_SRCS} ${BOX2D_Joints_HDRS})
source_group(Include FILES ${BOX2D_General_HDRS})
source_group(Rope FILES ${BOX2D_Rope_SRCS} ${BOX2D_Rope_HDRS})

if(BOX2D_INSTALL)
	# install headers
	install(FILES ${BOX2D_General_HDRS} DESTINATION include/Box2D)
	install(FILES ${BOX2D_Collision_HDRS} DESTINATION include/Box2D/Collision)
	install(FILES ${BOX2D_Shapes_HDRS} DESTINATION include/Box2D/Collision/Shapes)
	install(FILES ${BOX2D_Common_HDRS} DESTINATION include/Box2D/Common)
	install(FILES ${BOX2D_Dynamics_HDRS} DESTINATION include/Box2D/Dynamics)
	install(FILES ${BOX2D_Contacts_HDRS} DESTINATION include/Box2D/Dynamics/Contacts)
	install(FILES ${BOX2D_Joints_HDRS} DESTINATION include/Box2D/Dynamics/Joints)
	install(FILES ${BOX2D_Rope_HDRS} DESTINATION include/Box2D/Rope)

	# install libraries
	install(TARGETS Box2D EXPORT Box2D-targets DESTINATION ${LIB_INSTALL_DIR})
	# install build system hooks for third-party apps
	install(EXPORT Box2D-targets DESTINATION ${LIB_INSTALL_DIR}/Box2D)
	install(FILES Box2DConfig.cmake DESTINATION ${LIB_INSTALL_DIR}/Box2D)
endif(BOX2D_INSTALL)
