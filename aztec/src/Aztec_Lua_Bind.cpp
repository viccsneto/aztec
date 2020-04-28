/*
** Lua binding: Aztec_Lua_Bind
*/

#include "tolua.h"

#ifndef __cplusplus
#include <stdlib.h>
#endif
#ifdef __cplusplus
 extern "C" int tolua_bnd_takeownership (lua_State* L); // from tolua_map.c
#else
 int tolua_bnd_takeownership (lua_State* L); /* from tolua_map.c */
#endif
#include <string.h>

/* Exported function */
TOLUA_API int tolua_Aztec_Lua_Bind_open (lua_State* tolua_S);
LUALIB_API int luaopen_Aztec_Lua_Bind (lua_State* tolua_S);

#include "LuaBinded.h"
#include "Config.h"
#include "Vector2.h"
#include "Transform.h"
#include "GameEngine.h"
#include "Camera.h"
#include "GameObject.h"
#include "GameStateController.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "Music.h"
#include "Sound.h"
#include "Frame.h"
#include "Animation.h"
#include "Sensor.h"
#include "AutoSensor.h"
#include "Shader.h"
#include "Sprite.h"
#include "SpriteSensor.h"
#include "Text.h"
#include "EventTypes.h"
#include "Bitwise.h"
#include "Texture.h"
#include "VertexBufferObject.h"
#include "VertexArrayObject.h"
#include "Shape.h"
#include "Plane.h"
#include "WebBrowser.h"
#include "PointList2D.h"
#include "PropertyList.h"
#include "Aztec_Lua_Bind.h" 

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_Texture (lua_State* tolua_S)
{
 Texture* self = (Texture*) tolua_tousertype(tolua_S,1,0);
 tolua_release(tolua_S,self);
 delete self;
 return 0;
}

static int tolua_collect_VertexArrayObject (lua_State* tolua_S)
{
 VertexArrayObject* self = (VertexArrayObject*) tolua_tousertype(tolua_S,1,0);
 tolua_release(tolua_S,self);
 delete self;
 return 0;
}

static int tolua_collect_VertexBufferObject (lua_State* tolua_S)
{
 VertexBufferObject* self = (VertexBufferObject*) tolua_tousertype(tolua_S,1,0);
 tolua_release(tolua_S,self);
 delete self;
 return 0;
}

static int tolua_collect_PropertyList (lua_State* tolua_S)
{
 PropertyList* self = (PropertyList*) tolua_tousertype(tolua_S,1,0);
 tolua_release(tolua_S,self);
 delete self;
 return 0;
}

static int tolua_collect_Shader (lua_State* tolua_S)
{
 Shader* self = (Shader*) tolua_tousertype(tolua_S,1,0);
 tolua_release(tolua_S,self);
 delete self;
 return 0;
}

static int tolua_collect_Sound (lua_State* tolua_S)
{
 Sound* self = (Sound*) tolua_tousertype(tolua_S,1,0);
 tolua_release(tolua_S,self);
 delete self;
 return 0;
}

static int tolua_collect_Plane (lua_State* tolua_S)
{
 Plane* self = (Plane*) tolua_tousertype(tolua_S,1,0);
 tolua_release(tolua_S,self);
 delete self;
 return 0;
}

static int tolua_collect_GameStateController (lua_State* tolua_S)
{
 GameStateController* self = (GameStateController*) tolua_tousertype(tolua_S,1,0);
 tolua_release(tolua_S,self);
 delete self;
 return 0;
}

static int tolua_collect_PointList2D (lua_State* tolua_S)
{
 PointList2D* self = (PointList2D*) tolua_tousertype(tolua_S,1,0);
 tolua_release(tolua_S,self);
 delete self;
 return 0;
}

static int tolua_collect_Shape (lua_State* tolua_S)
{
 Shape* self = (Shape*) tolua_tousertype(tolua_S,1,0);
 tolua_release(tolua_S,self);
 delete self;
 return 0;
}

static int tolua_collect_AutoSensor (lua_State* tolua_S)
{
 AutoSensor* self = (AutoSensor*) tolua_tousertype(tolua_S,1,0);
 tolua_release(tolua_S,self);
 delete self;
 return 0;
}

static int tolua_collect_Transform (lua_State* tolua_S)
{
 Transform* self = (Transform*) tolua_tousertype(tolua_S,1,0);
 tolua_release(tolua_S,self);
 delete self;
 return 0;
}

static int tolua_collect_GameObjectList (lua_State* tolua_S)
{
 GameObjectList* self = (GameObjectList*) tolua_tousertype(tolua_S,1,0);
 tolua_release(tolua_S,self);
 delete self;
 return 0;
}

static int tolua_collect_Sensor (lua_State* tolua_S)
{
 Sensor* self = (Sensor*) tolua_tousertype(tolua_S,1,0);
 tolua_release(tolua_S,self);
 delete self;
 return 0;
}

static int tolua_collect_Vector2 (lua_State* tolua_S)
{
 Vector2* self = (Vector2*) tolua_tousertype(tolua_S,1,0);
 tolua_release(tolua_S,self);
 delete self;
 return 0;
}

static int tolua_collect_Music (lua_State* tolua_S)
{
 Music* self = (Music*) tolua_tousertype(tolua_S,1,0);
 tolua_release(tolua_S,self);
 delete self;
 return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"Camera");
 tolua_usertype(tolua_S,"Mouse");
 tolua_usertype(tolua_S,"GameObjectList");
 tolua_usertype(tolua_S,"Shader");
 tolua_usertype(tolua_S,"Sound");
 tolua_usertype(tolua_S,"LuaBinded");
 tolua_usertype(tolua_S,"GameStateController");
 tolua_usertype(tolua_S,"EventTypes");
 tolua_usertype(tolua_S,"Plane");
 tolua_usertype(tolua_S,"AutoSensor");
 tolua_usertype(tolua_S,"Frame");
 tolua_usertype(tolua_S,"VertexBufferObject");
 tolua_usertype(tolua_S,"GameObject");
 tolua_usertype(tolua_S,"VertexArrayObject");
 tolua_usertype(tolua_S,"Shape");
 tolua_usertype(tolua_S,"Bitwise");
 tolua_usertype(tolua_S,"SpriteSensor");
 tolua_usertype(tolua_S,"Keyboard");
 tolua_usertype(tolua_S,"PropertyList");
 tolua_usertype(tolua_S,"Animation");
 tolua_usertype(tolua_S,"Sensor");
 tolua_usertype(tolua_S,"Texture");
 tolua_usertype(tolua_S,"WebBrowser");
 tolua_usertype(tolua_S,"PointList2D");
 tolua_usertype(tolua_S,"Text");
 tolua_usertype(tolua_S,"GameEngine");
 tolua_usertype(tolua_S,"Transform");
 tolua_usertype(tolua_S,"Sprite");
 tolua_usertype(tolua_S,"Config");
 tolua_usertype(tolua_S,"Vector2");
 tolua_usertype(tolua_S,"Music");
}

/* get function: EventFlags of class  LuaBinded */
static int tolua_get_LuaBinded_LuaBinded_EventFlags(lua_State* tolua_S)
{
  LuaBinded* self = (LuaBinded*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'EventFlags'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->EventFlags);
 return 1;
}

/* set function: EventFlags of class  LuaBinded */
static int tolua_set_LuaBinded_LuaBinded_EventFlags(lua_State* tolua_S)
{
  LuaBinded* self = (LuaBinded*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'EventFlags'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->EventFlags = ((long)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* method: resetEventFlags of class  LuaBinded */
static int tolua_Aztec_Lua_Bind_LuaBinded_resetEventFlags00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"LuaBinded",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  LuaBinded* self = (LuaBinded*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'resetEventFlags'",NULL);
#endif
 {
  self->resetEventFlags();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'resetEventFlags'.",&tolua_err);
 return 0;
#endif
}

/* method: getClassName of class  LuaBinded */
static int tolua_Aztec_Lua_Bind_LuaBinded_getClassName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"LuaBinded",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  LuaBinded* self = (LuaBinded*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getClassName'",NULL);
#endif
 {
  const char* tolua_ret = (const char*)  self->getClassName();
 tolua_pushstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getClassName'.",&tolua_err);
 return 0;
#endif
}

/* get function: ZERO of class  Vector2 */
static int tolua_get_Vector2_Vector2_ZERO(lua_State* tolua_S)
{
 tolua_pushusertype(tolua_S,(void*)&Vector2::ZERO,"const Vector2");
 return 1;
}

/* get function: x of class  Vector2 */
static int tolua_get_Vector2_Vector2_x(lua_State* tolua_S)
{
  Vector2* self = (Vector2*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->x);
 return 1;
}

/* set function: x of class  Vector2 */
static int tolua_set_Vector2_Vector2_x(lua_State* tolua_S)
{
  Vector2* self = (Vector2*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->x = ((float)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* get function: y of class  Vector2 */
static int tolua_get_Vector2_Vector2_y(lua_State* tolua_S)
{
  Vector2* self = (Vector2*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->y);
 return 1;
}

/* set function: y of class  Vector2 */
static int tolua_set_Vector2_Vector2_y(lua_State* tolua_S)
{
  Vector2* self = (Vector2*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->y = ((float)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* method: assign of class  Vector2 */
static int tolua_Aztec_Lua_Bind_Vector2_assign00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Vector2",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"Vector2",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Vector2* self = (Vector2*)  tolua_tousertype(tolua_S,1,0);
  Vector2* other = ((Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'assign'",NULL);
#endif
 {
  Vector2* tolua_ret = (Vector2*)  self->assign(*other);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Vector2");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'assign'.",&tolua_err);
 return 0;
#endif
}

/* method: equals of class  Vector2 */
static int tolua_Aztec_Lua_Bind_Vector2_equals00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Vector2",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"Vector2",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Vector2* self = (Vector2*)  tolua_tousertype(tolua_S,1,0);
  Vector2* other = ((Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'equals'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->equals(*other);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'equals'.",&tolua_err);
 return 0;
#endif
}

/* method: set of class  Vector2 */
static int tolua_Aztec_Lua_Bind_Vector2_set00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Vector2",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Vector2* self = (Vector2*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set'",NULL);
#endif
 {
  self->set(x,y);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set'.",&tolua_err);
 return 0;
#endif
}

/* method: add of class  Vector2 */
static int tolua_Aztec_Lua_Bind_Vector2_add00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Vector2",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Vector2* self = (Vector2*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'add'",NULL);
#endif
 {
  self->add(x,y);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'add'.",&tolua_err);
 return 0;
#endif
}

/* method: sub of class  Vector2 */
static int tolua_Aztec_Lua_Bind_Vector2_sub00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Vector2",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Vector2* self = (Vector2*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'sub'",NULL);
#endif
 {
  self->sub(x,y);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'sub'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  Vector2 */
static int tolua_Aztec_Lua_Bind_Vector2_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Vector2",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Vector2* tolua_ret = (Vector2*)  new Vector2();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Vector2");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  Vector2 */
static int tolua_Aztec_Lua_Bind_Vector2_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Vector2",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
 {
  Vector2* tolua_ret = (Vector2*)  new Vector2(x,y);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Vector2");
 }
 }
 return 1;
tolua_lerror:
 return tolua_Aztec_Lua_Bind_Vector2_new00(tolua_S);
}

/* method: delete of class  Vector2 */
static int tolua_Aztec_Lua_Bind_Vector2_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Vector2",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Vector2* self = (Vector2*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
 tolua_release(tolua_S,self);
 delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  Transform */
static int tolua_Aztec_Lua_Bind_Transform_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Transform",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Transform* tolua_ret = (Transform*)  new Transform();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Transform");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  Transform */
static int tolua_Aztec_Lua_Bind_Transform_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Transform",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Transform* self = (Transform*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
 tolua_release(tolua_S,self);
 delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* get function: position of class  Transform */
static int tolua_get_Transform_Transform_position(lua_State* tolua_S)
{
  Transform* self = (Transform*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'position'",NULL);
#endif
 tolua_pushusertype(tolua_S,(void*)&self->position,"Vector2");
 return 1;
}

/* set function: position of class  Transform */
static int tolua_set_Transform_Transform_position(lua_State* tolua_S)
{
  Transform* self = (Transform*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'position'",NULL);
 if (!tolua_isusertype(tolua_S,2,"Vector2",0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->position = *((Vector2*)  tolua_tousertype(tolua_S,2,0));
 return 0;
}

/* get function: scale of class  Transform */
static int tolua_get_Transform_Transform_scale(lua_State* tolua_S)
{
  Transform* self = (Transform*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'scale'",NULL);
#endif
 tolua_pushusertype(tolua_S,(void*)&self->scale,"Vector2");
 return 1;
}

/* set function: scale of class  Transform */
static int tolua_set_Transform_Transform_scale(lua_State* tolua_S)
{
  Transform* self = (Transform*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'scale'",NULL);
 if (!tolua_isusertype(tolua_S,2,"Vector2",0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->scale = *((Vector2*)  tolua_tousertype(tolua_S,2,0));
 return 0;
}

/* get function: rotation of class  Transform */
static int tolua_get_Transform_Transform_rotation(lua_State* tolua_S)
{
  Transform* self = (Transform*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'rotation'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->rotation);
 return 1;
}

/* set function: rotation of class  Transform */
static int tolua_set_Transform_Transform_rotation(lua_State* tolua_S)
{
  Transform* self = (Transform*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'rotation'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->rotation = ((float)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* get function: zorder of class  Transform */
static int tolua_get_Transform_Transform_zorder(lua_State* tolua_S)
{
  Transform* self = (Transform*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'zorder'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->zorder);
 return 1;
}

/* set function: zorder of class  Transform */
static int tolua_set_Transform_Transform_zorder(lua_State* tolua_S)
{
  Transform* self = (Transform*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'zorder'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->zorder = ((float)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* method: new of class  Music */
static int tolua_Aztec_Lua_Bind_Music_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Music",0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const char* path = ((const char*)  tolua_tostring(tolua_S,2,0));
 {
  Music* tolua_ret = (Music*)  new Music(path);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Music");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: Play of class  Music */
static int tolua_Aztec_Lua_Bind_Music_Play00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Music",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Music* self = (Music*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Play'",NULL);
#endif
 {
  self->Play();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Play'.",&tolua_err);
 return 0;
#endif
}

/* method: Stop of class  Music */
static int tolua_Aztec_Lua_Bind_Music_Stop00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Music",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Music* self = (Music*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Stop'",NULL);
#endif
 {
  self->Stop();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Stop'.",&tolua_err);
 return 0;
#endif
}

/* method: Pause of class  Music */
static int tolua_Aztec_Lua_Bind_Music_Pause00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Music",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Music* self = (Music*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Pause'",NULL);
#endif
 {
  self->Pause();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Pause'.",&tolua_err);
 return 0;
#endif
}

/* method: Resume of class  Music */
static int tolua_Aztec_Lua_Bind_Music_Resume00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Music",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Music* self = (Music*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Resume'",NULL);
#endif
 {
  self->Resume();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Resume'.",&tolua_err);
 return 0;
#endif
}

/* method: Seek of class  Music */
static int tolua_Aztec_Lua_Bind_Music_Seek00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Music",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Music* self = (Music*)  tolua_tousertype(tolua_S,1,0);
  double time = ((double)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Seek'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->Seek(time);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Seek'.",&tolua_err);
 return 0;
#endif
}

/* method: setVolume of class  Music */
static int tolua_Aztec_Lua_Bind_Music_setVolume00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Music",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Music* self = (Music*)  tolua_tousertype(tolua_S,1,0);
  double volume = ((double)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setVolume'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->setVolume(volume);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setVolume'.",&tolua_err);
 return 0;
#endif
}

/* get function: Repeat of class  Music */
static int tolua_get_Music_Music_Repeat(lua_State* tolua_S)
{
  Music* self = (Music*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Repeat'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->Repeat);
 return 1;
}

/* set function: Repeat of class  Music */
static int tolua_set_Music_Music_Repeat(lua_State* tolua_S)
{
  Music* self = (Music*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Repeat'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Repeat = ((bool)  tolua_toboolean(tolua_S,2,0));
 return 0;
}

/* method: isPlaying of class  Music */
static int tolua_Aztec_Lua_Bind_Music_isPlaying00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Music",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Music* self = (Music*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isPlaying'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->isPlaying();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isPlaying'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  Music */
static int tolua_Aztec_Lua_Bind_Music_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Music",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Music* self = (Music*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
 tolua_release(tolua_S,self);
 delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  Sound */
static int tolua_Aztec_Lua_Bind_Sound_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Sound",0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const char* path = ((const char*)  tolua_tostring(tolua_S,2,0));
 {
  Sound* tolua_ret = (Sound*)  new Sound(path);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Sound");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: Play of class  Sound */
static int tolua_Aztec_Lua_Bind_Sound_Play00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Sound",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Sound* self = (Sound*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Play'",NULL);
#endif
 {
  self->Play();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Play'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  Sound */
static int tolua_Aztec_Lua_Bind_Sound_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Sound",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Sound* self = (Sound*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
 tolua_release(tolua_S,self);
 delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* get function: hasClick of class  Mouse */
static int tolua_get_Mouse_Mouse_hasClick(lua_State* tolua_S)
{
 tolua_pushboolean(tolua_S,(bool)Mouse::hasClick);
 return 1;
}

/* set function: hasClick of class  Mouse */
static int tolua_set_Mouse_Mouse_hasClick(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  Mouse::hasClick = ((bool)  tolua_toboolean(tolua_S,2,0));
 return 0;
}

/* get function: hasMovement of class  Mouse */
static int tolua_get_Mouse_Mouse_hasMovement(lua_State* tolua_S)
{
 tolua_pushboolean(tolua_S,(bool)Mouse::hasMovement);
 return 1;
}

/* set function: hasMovement of class  Mouse */
static int tolua_set_Mouse_Mouse_hasMovement(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  Mouse::hasMovement = ((bool)  tolua_toboolean(tolua_S,2,0));
 return 0;
}

/* method: getPosX of class  Mouse */
static int tolua_Aztec_Lua_Bind_Mouse_getPosX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Mouse",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Mouse* self = (Mouse*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPosX'",NULL);
#endif
 {
  int tolua_ret = (int)  self->getPosX();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPosX'.",&tolua_err);
 return 0;
#endif
}

/* method: getPosY of class  Mouse */
static int tolua_Aztec_Lua_Bind_Mouse_getPosY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Mouse",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Mouse* self = (Mouse*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPosY'",NULL);
#endif
 {
  int tolua_ret = (int)  self->getPosY();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPosY'.",&tolua_err);
 return 0;
#endif
}

/* method: isLeftButtonPressed of class  Mouse */
static int tolua_Aztec_Lua_Bind_Mouse_isLeftButtonPressed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Mouse",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Mouse* self = (Mouse*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isLeftButtonPressed'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->isLeftButtonPressed();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isLeftButtonPressed'.",&tolua_err);
 return 0;
#endif
}

/* method: isMiddleButtonPressed of class  Mouse */
static int tolua_Aztec_Lua_Bind_Mouse_isMiddleButtonPressed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Mouse",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Mouse* self = (Mouse*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isMiddleButtonPressed'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->isMiddleButtonPressed();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isMiddleButtonPressed'.",&tolua_err);
 return 0;
#endif
}

/* method: isRightButtonPressed of class  Mouse */
static int tolua_Aztec_Lua_Bind_Mouse_isRightButtonPressed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Mouse",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Mouse* self = (Mouse*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isRightButtonPressed'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->isRightButtonPressed();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isRightButtonPressed'.",&tolua_err);
 return 0;
#endif
}

/* method: hideCursor of class  Mouse */
static int tolua_Aztec_Lua_Bind_Mouse_hideCursor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Mouse",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Mouse* self = (Mouse*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'hideCursor'",NULL);
#endif
 {
  self->hideCursor();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'hideCursor'.",&tolua_err);
 return 0;
#endif
}

/* method: showCursor of class  Mouse */
static int tolua_Aztec_Lua_Bind_Mouse_showCursor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Mouse",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Mouse* self = (Mouse*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'showCursor'",NULL);
#endif
 {
  self->showCursor();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'showCursor'.",&tolua_err);
 return 0;
#endif
}

/* get function: UP_KEY of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_UP_KEY(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::UP_KEY);
 return 1;
}

/* get function: DOWN_KEY of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_DOWN_KEY(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::DOWN_KEY);
 return 1;
}

/* get function: RIGHT_KEY of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_RIGHT_KEY(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::RIGHT_KEY);
 return 1;
}

/* get function: LEFT_KEY of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_LEFT_KEY(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::LEFT_KEY);
 return 1;
}

/* get function: ESCAPE_KEY of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_ESCAPE_KEY(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::ESCAPE_KEY);
 return 1;
}

/* get function: SPACE_KEY of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_SPACE_KEY(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::SPACE_KEY);
 return 1;
}

/* get function: ENTER_KEY of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_ENTER_KEY(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::ENTER_KEY);
 return 1;
}

/* get function: zero of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_zero(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::zero);
 return 1;
}

/* get function: one of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_one(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::one);
 return 1;
}

/* get function: two of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_two(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::two);
 return 1;
}

/* get function: three of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_three(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::three);
 return 1;
}

/* get function: four of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_four(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::four);
 return 1;
}

/* get function: five of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_five(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::five);
 return 1;
}

/* get function: six of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_six(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::six);
 return 1;
}

/* get function: seven of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_seven(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::seven);
 return 1;
}

/* get function: eight of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_eight(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::eight);
 return 1;
}

/* get function: nine of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_nine(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::nine);
 return 1;
}

/* get function: KEY_UNKNOWN of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_UNKNOWN(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_UNKNOWN);
 return 1;
}

/* get function: KEY_FIND of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_FIND(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_FIND);
 return 1;
}

/* get function: KEY_BACKSPACE of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_BACKSPACE(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_BACKSPACE);
 return 1;
}

/* get function: KEY_TAB of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_TAB(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_TAB);
 return 1;
}

/* get function: KEY_CLEAR of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_CLEAR(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_CLEAR);
 return 1;
}

/* get function: KEY_RETURN of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_RETURN(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_RETURN);
 return 1;
}

/* get function: KEY_PAUSE of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_PAUSE(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_PAUSE);
 return 1;
}

/* get function: KEY_ESCAPE of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_ESCAPE(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_ESCAPE);
 return 1;
}

/* get function: KEY_SPACE of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_SPACE(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_SPACE);
 return 1;
}

/* get function: KEY_EXCLAIM of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_EXCLAIM(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_EXCLAIM);
 return 1;
}

/* get function: KEY_QUOTEDBL of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_QUOTEDBL(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_QUOTEDBL);
 return 1;
}

/* get function: KEY_HASH of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_HASH(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_HASH);
 return 1;
}

/* get function: KEY_DOLLAR of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_DOLLAR(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_DOLLAR);
 return 1;
}

/* get function: KEY_AMPERSAND of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_AMPERSAND(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_AMPERSAND);
 return 1;
}

/* get function: KEY_QUOTE of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_QUOTE(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_QUOTE);
 return 1;
}

/* get function: KEY_LEFTPAREN of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_LEFTPAREN(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_LEFTPAREN);
 return 1;
}

/* get function: KEY_RIGHTPAREN of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_RIGHTPAREN(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_RIGHTPAREN);
 return 1;
}

/* get function: KEY_ASTERISK of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_ASTERISK(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_ASTERISK);
 return 1;
}

/* get function: KEY_PLUS of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_PLUS(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_PLUS);
 return 1;
}

/* get function: KEY_COMMA of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_COMMA(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_COMMA);
 return 1;
}

/* get function: KEY_MINUS of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_MINUS(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_MINUS);
 return 1;
}

/* get function: KEY_PERIOD of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_PERIOD(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_PERIOD);
 return 1;
}

/* get function: KEY_SLASH of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_SLASH(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_SLASH);
 return 1;
}

/* get function: KEY_0 of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_0(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_0);
 return 1;
}

/* get function: KEY_1 of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_1(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_1);
 return 1;
}

/* get function: KEY_2 of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_2(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_2);
 return 1;
}

/* get function: KEY_3 of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_3(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_3);
 return 1;
}

/* get function: KEY_4 of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_4(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_4);
 return 1;
}

/* get function: KEY_5 of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_5(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_5);
 return 1;
}

/* get function: KEY_6 of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_6(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_6);
 return 1;
}

/* get function: KEY_7 of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_7(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_7);
 return 1;
}

/* get function: KEY_8 of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_8(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_8);
 return 1;
}

/* get function: KEY_9 of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_9(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_9);
 return 1;
}

/* get function: KEY_COLON of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_COLON(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_COLON);
 return 1;
}

/* get function: KEY_SEMICOLON of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_SEMICOLON(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_SEMICOLON);
 return 1;
}

/* get function: KEY_LESS of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_LESS(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_LESS);
 return 1;
}

/* get function: KEY_EQUALS of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_EQUALS(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_EQUALS);
 return 1;
}

/* get function: KEY_GREATER of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_GREATER(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_GREATER);
 return 1;
}

/* get function: KEY_QUESTION of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_QUESTION(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_QUESTION);
 return 1;
}

/* get function: KEY_AT of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_AT(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_AT);
 return 1;
}

/* get function: KEY_LEFTBRACKET of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_LEFTBRACKET(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_LEFTBRACKET);
 return 1;
}

/* get function: KEY_BACKSLASH of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_BACKSLASH(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_BACKSLASH);
 return 1;
}

/* get function: KEY_RIGHTBRACKET of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_RIGHTBRACKET(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_RIGHTBRACKET);
 return 1;
}

/* get function: KEY_CARET of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_CARET(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_CARET);
 return 1;
}

/* get function: KEY_UNDERSCORE of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_UNDERSCORE(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_UNDERSCORE);
 return 1;
}

/* get function: KEY_BACKQUOTE of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_BACKQUOTE(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_BACKQUOTE);
 return 1;
}

/* get function: KEY_a of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_a(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_a);
 return 1;
}

/* get function: KEY_b of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_b(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_b);
 return 1;
}

/* get function: KEY_c of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_c(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_c);
 return 1;
}

/* get function: KEY_d of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_d(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_d);
 return 1;
}

/* get function: KEY_e of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_e(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_e);
 return 1;
}

/* get function: KEY_f of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_f(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_f);
 return 1;
}

/* get function: KEY_g of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_g(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_g);
 return 1;
}

/* get function: KEY_h of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_h(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_h);
 return 1;
}

/* get function: KEY_i of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_i(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_i);
 return 1;
}

/* get function: KEY_j of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_j(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_j);
 return 1;
}

/* get function: KEY_k of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_k(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_k);
 return 1;
}

/* get function: KEY_l of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_l(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_l);
 return 1;
}

/* get function: KEY_m of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_m(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_m);
 return 1;
}

/* get function: KEY_n of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_n(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_n);
 return 1;
}

/* get function: KEY_o of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_o(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_o);
 return 1;
}

/* get function: KEY_p of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_p(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_p);
 return 1;
}

/* get function: KEY_q of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_q(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_q);
 return 1;
}

/* get function: KEY_r of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_r(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_r);
 return 1;
}

/* get function: KEY_s of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_s(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_s);
 return 1;
}

/* get function: KEY_t of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_t(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_t);
 return 1;
}

/* get function: KEY_u of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_u(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_u);
 return 1;
}

/* get function: KEY_v of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_v(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_v);
 return 1;
}

/* get function: KEY_w of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_w(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_w);
 return 1;
}

/* get function: KEY_x of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_x(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_x);
 return 1;
}

/* get function: KEY_y of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_y(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_y);
 return 1;
}

/* get function: KEY_z of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_z(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_z);
 return 1;
}

/* get function: KEY_DELETE of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_DELETE(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_DELETE);
 return 1;
}

/* get function: KEY_KP0 of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_KP0(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_KP0);
 return 1;
}

/* get function: KEY_KP1 of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_KP1(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_KP1);
 return 1;
}

/* get function: KEY_KP2 of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_KP2(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_KP2);
 return 1;
}

/* get function: KEY_KP3 of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_KP3(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_KP3);
 return 1;
}

/* get function: KEY_KP4 of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_KP4(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_KP4);
 return 1;
}

/* get function: KEY_KP5 of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_KP5(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_KP5);
 return 1;
}

/* get function: KEY_KP6 of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_KP6(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_KP6);
 return 1;
}

/* get function: KEY_KP7 of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_KP7(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_KP7);
 return 1;
}

/* get function: KEY_KP8 of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_KP8(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_KP8);
 return 1;
}

/* get function: KEY_KP9 of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_KP9(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_KP9);
 return 1;
}

/* get function: KEY_KP_PERIOD of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_KP_PERIOD(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_KP_PERIOD);
 return 1;
}

/* get function: KEY_KP_DIVIDE of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_KP_DIVIDE(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_KP_DIVIDE);
 return 1;
}

/* get function: KEY_KP_MULTIPLY of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_KP_MULTIPLY(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_KP_MULTIPLY);
 return 1;
}

/* get function: KEY_KP_MINUS of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_KP_MINUS(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_KP_MINUS);
 return 1;
}

/* get function: KEY_KP_PLUS of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_KP_PLUS(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_KP_PLUS);
 return 1;
}

/* get function: KEY_KP_ENTER of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_KP_ENTER(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_KP_ENTER);
 return 1;
}

/* get function: KEY_KP_EQUALS of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_KP_EQUALS(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_KP_EQUALS);
 return 1;
}

/* get function: KEY_UP of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_UP(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_UP);
 return 1;
}

/* get function: KEY_DOWN of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_DOWN(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_DOWN);
 return 1;
}

/* get function: KEY_RIGHT of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_RIGHT(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_RIGHT);
 return 1;
}

/* get function: KEY_LEFT of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_LEFT(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_LEFT);
 return 1;
}

/* get function: KEY_INSERT of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_INSERT(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_INSERT);
 return 1;
}

/* get function: KEY_HOME of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_HOME(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_HOME);
 return 1;
}

/* get function: KEY_END of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_END(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_END);
 return 1;
}

/* get function: KEY_ENTER of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_ENTER(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_ENTER);
 return 1;
}

/* get function: KEY_PAGEUP of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_PAGEUP(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_PAGEUP);
 return 1;
}

/* get function: KEY_PAGEDOWN of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_PAGEDOWN(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_PAGEDOWN);
 return 1;
}

/* get function: KEY_F1 of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_F1(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_F1);
 return 1;
}

/* get function: KEY_F2 of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_F2(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_F2);
 return 1;
}

/* get function: KEY_F3 of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_F3(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_F3);
 return 1;
}

/* get function: KEY_F4 of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_F4(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_F4);
 return 1;
}

/* get function: KEY_F5 of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_F5(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_F5);
 return 1;
}

/* get function: KEY_F6 of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_F6(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_F6);
 return 1;
}

/* get function: KEY_F7 of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_F7(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_F7);
 return 1;
}

/* get function: KEY_F8 of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_F8(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_F8);
 return 1;
}

/* get function: KEY_F9 of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_F9(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_F9);
 return 1;
}

/* get function: KEY_F10 of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_F10(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_F10);
 return 1;
}

/* get function: KEY_F11 of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_F11(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_F11);
 return 1;
}

/* get function: KEY_F12 of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_F12(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_F12);
 return 1;
}

/* get function: KEY_F13 of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_F13(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_F13);
 return 1;
}

/* get function: KEY_F14 of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_F14(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_F14);
 return 1;
}

/* get function: KEY_F15 of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_F15(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_F15);
 return 1;
}

/* get function: KEY_NUMLOCK of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_NUMLOCK(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_NUMLOCK);
 return 1;
}

/* get function: KEY_CAPSLOCK of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_CAPSLOCK(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_CAPSLOCK);
 return 1;
}

/* get function: KEY_SCROLLLOCK of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_SCROLLLOCK(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_SCROLLLOCK);
 return 1;
}

/* get function: KEY_RSHIFT of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_RSHIFT(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_RSHIFT);
 return 1;
}

/* get function: KEY_LSHIFT of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_LSHIFT(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_LSHIFT);
 return 1;
}

/* get function: KEY_RCTRL of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_RCTRL(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_RCTRL);
 return 1;
}

/* get function: KEY_LCTRL of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_LCTRL(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_LCTRL);
 return 1;
}

/* get function: KEY_RALT of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_RALT(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_RALT);
 return 1;
}

/* get function: KEY_LALT of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_LALT(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_LALT);
 return 1;
}

/* get function: KEY_MODE of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_MODE(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_MODE);
 return 1;
}

/* get function: KEY_HELP of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_HELP(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_HELP);
 return 1;
}

/* get function: KEY_PRINT of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_PRINT(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_PRINT);
 return 1;
}

/* get function: KEY_SYSREQ of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_SYSREQ(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_SYSREQ);
 return 1;
}

/* get function: KEY_MENU of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_MENU(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_MENU);
 return 1;
}

/* get function: KEY_POWER of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_POWER(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_POWER);
 return 1;
}

/* get function: KEY_UNDO of class  Keyboard */
static int tolua_get_Keyboard_Keyboard_KEY_UNDO(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Keyboard::KEY_UNDO);
 return 1;
}

/* method: isShiftPressed of class  Keyboard */
static int tolua_Aztec_Lua_Bind_Keyboard_isShiftPressed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Keyboard",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Keyboard* self = (Keyboard*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isShiftPressed'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->isShiftPressed();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isShiftPressed'.",&tolua_err);
 return 0;
#endif
}

/* method: isControlPressed of class  Keyboard */
static int tolua_Aztec_Lua_Bind_Keyboard_isControlPressed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Keyboard",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Keyboard* self = (Keyboard*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isControlPressed'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->isControlPressed();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isControlPressed'.",&tolua_err);
 return 0;
#endif
}

/* method: isAltPressed of class  Keyboard */
static int tolua_Aztec_Lua_Bind_Keyboard_isAltPressed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Keyboard",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Keyboard* self = (Keyboard*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isAltPressed'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->isAltPressed();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isAltPressed'.",&tolua_err);
 return 0;
#endif
}

/* method: keyIsDown of class  Keyboard */
static int tolua_Aztec_Lua_Bind_Keyboard_keyIsDown00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Keyboard",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Keyboard* self = (Keyboard*)  tolua_tousertype(tolua_S,1,0);
  int keyCode = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'keyIsDown'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->keyIsDown(keyCode);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'keyIsDown'.",&tolua_err);
 return 0;
#endif
}

/* method: keyIsUp of class  Keyboard */
static int tolua_Aztec_Lua_Bind_Keyboard_keyIsUp00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Keyboard",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Keyboard* self = (Keyboard*)  tolua_tousertype(tolua_S,1,0);
  int keyCode = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'keyIsUp'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->keyIsUp(keyCode);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'keyIsUp'.",&tolua_err);
 return 0;
#endif
}

/* method: bufferLength of class  Keyboard */
static int tolua_Aztec_Lua_Bind_Keyboard_bufferLength00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Keyboard",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Keyboard* self = (Keyboard*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'bufferLength'",NULL);
#endif
 {
  int tolua_ret = (int)  self->bufferLength();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'bufferLength'.",&tolua_err);
 return 0;
#endif
}

/* method: readBuffer of class  Keyboard */
static int tolua_Aztec_Lua_Bind_Keyboard_readBuffer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Keyboard",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Keyboard* self = (Keyboard*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'readBuffer'",NULL);
#endif
 {
  int tolua_ret = (int)  self->readBuffer();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'readBuffer'.",&tolua_err);
 return 0;
#endif
}

/* method: cleanBuffer of class  Keyboard */
static int tolua_Aztec_Lua_Bind_Keyboard_cleanBuffer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Keyboard",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Keyboard* self = (Keyboard*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'cleanBuffer'",NULL);
#endif
 {
  self->cleanBuffer();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'cleanBuffer'.",&tolua_err);
 return 0;
#endif
}

/* method: cleanPressed of class  Keyboard */
static int tolua_Aztec_Lua_Bind_Keyboard_cleanPressed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Keyboard",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Keyboard* self = (Keyboard*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'cleanPressed'",NULL);
#endif
 {
  self->cleanPressed();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'cleanPressed'.",&tolua_err);
 return 0;
#endif
}

/* method: reset of class  Keyboard */
static int tolua_Aztec_Lua_Bind_Keyboard_reset00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Keyboard",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Keyboard* self = (Keyboard*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'reset'",NULL);
#endif
 {
  self->reset();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'reset'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  GameObject */
static int tolua_Aztec_Lua_Bind_GameObject_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"GameObject",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  GameObject* tolua_ret = (GameObject*)  new GameObject();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"GameObject");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* get function: Transform of class  GameObject */
static int tolua_get_GameObject_GameObject_Transform(lua_State* tolua_S)
{
  GameObject* self = (GameObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Transform'",NULL);
#endif
 tolua_pushusertype(tolua_S,(void*)&self->Transform,"Transform");
 return 1;
}

/* set function: Transform of class  GameObject */
static int tolua_set_GameObject_GameObject_Transform(lua_State* tolua_S)
{
  GameObject* self = (GameObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Transform'",NULL);
 if (!tolua_isusertype(tolua_S,2,"Transform",0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Transform = *((Transform*)  tolua_tousertype(tolua_S,2,0));
 return 0;
}

/* method: getZOrder of class  GameObject */
static int tolua_Aztec_Lua_Bind_GameObject_getZOrder00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GameObject* self = (GameObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getZOrder'",NULL);
#endif
 {
  int tolua_ret = (int)  self->getZOrder();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getZOrder'.",&tolua_err);
 return 0;
#endif
}

/* method: setZOrder of class  GameObject */
static int tolua_Aztec_Lua_Bind_GameObject_setZOrder00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GameObject* self = (GameObject*)  tolua_tousertype(tolua_S,1,0);
  int zorder = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setZOrder'",NULL);
#endif
 {
  int tolua_ret = (int)  self->setZOrder(zorder);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setZOrder'.",&tolua_err);
 return 0;
#endif
}

/* method: getGlobalTransform of class  GameObject */
static int tolua_Aztec_Lua_Bind_GameObject_getGlobalTransform00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GameObject* self = (GameObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getGlobalTransform'",NULL);
#endif
 {
  Transform tolua_ret =  self->getGlobalTransform();
 {
#ifdef __cplusplus
 void* tolua_obj = new Transform(tolua_ret);
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect_Transform),"Transform");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Transform));
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,NULL),"Transform");
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getGlobalTransform'.",&tolua_err);
 return 0;
#endif
}

/* method: getParent of class  GameObject */
static int tolua_Aztec_Lua_Bind_GameObject_getParent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GameObject* self = (GameObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getParent'",NULL);
#endif
 {
  GameObject* tolua_ret = (GameObject*)  self->getParent();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"GameObject");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getParent'.",&tolua_err);
 return 0;
#endif
}

/* method: addGameObject of class  GameObject */
static int tolua_Aztec_Lua_Bind_GameObject_addGameObject00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"GameObject",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GameObject* self = (GameObject*)  tolua_tousertype(tolua_S,1,0);
  GameObject* object = ((GameObject*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addGameObject'",NULL);
#endif
 {
  GameObject* tolua_ret = (GameObject*)  self->addGameObject(object);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"GameObject");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addGameObject'.",&tolua_err);
 return 0;
#endif
}

/* method: removeGameObject of class  GameObject */
static int tolua_Aztec_Lua_Bind_GameObject_removeGameObject00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"GameObject",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GameObject* self = (GameObject*)  tolua_tousertype(tolua_S,1,0);
  GameObject* object = ((GameObject*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeGameObject'",NULL);
#endif
 {
  GameObject* tolua_ret = (GameObject*)  self->removeGameObject(object);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"GameObject");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeGameObject'.",&tolua_err);
 return 0;
#endif
}

/* get function: Visible of class  GameObject */
static int tolua_get_GameObject_GameObject_Visible(lua_State* tolua_S)
{
  GameObject* self = (GameObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Visible'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->Visible);
 return 1;
}

/* set function: Visible of class  GameObject */
static int tolua_set_GameObject_GameObject_Visible(lua_State* tolua_S)
{
  GameObject* self = (GameObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Visible'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Visible = ((bool)  tolua_toboolean(tolua_S,2,0));
 return 0;
}

/* get function: Enabled of class  GameObject */
static int tolua_get_GameObject_GameObject_Enabled(lua_State* tolua_S)
{
  GameObject* self = (GameObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Enabled'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->Enabled);
 return 1;
}

/* set function: Enabled of class  GameObject */
static int tolua_set_GameObject_GameObject_Enabled(lua_State* tolua_S)
{
  GameObject* self = (GameObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Enabled'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Enabled = ((bool)  tolua_toboolean(tolua_S,2,0));
 return 0;
}

/* method: setPivot of class  GameObject */
static int tolua_Aztec_Lua_Bind_GameObject_setPivot00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GameObject* self = (GameObject*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPivot'",NULL);
#endif
 {
  self->setPivot(x,y);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setPivot'.",&tolua_err);
 return 0;
#endif
}

/* method: getPivot of class  GameObject */
static int tolua_Aztec_Lua_Bind_GameObject_getPivot00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GameObject* self = (GameObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPivot'",NULL);
#endif
 {
  Vector2 tolua_ret =  self->getPivot();
 {
#ifdef __cplusplus
 void* tolua_obj = new Vector2(tolua_ret);
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect_Vector2),"Vector2");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector2));
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,NULL),"Vector2");
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPivot'.",&tolua_err);
 return 0;
#endif
}

/* method: destroy of class  GameObject */
static int tolua_Aztec_Lua_Bind_GameObject_destroy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GameObject* self = (GameObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'destroy'",NULL);
#endif
 {
  self->destroy();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'destroy'.",&tolua_err);
 return 0;
#endif
}

/* method: setClipRect of class  GameObject */
static int tolua_Aztec_Lua_Bind_GameObject_setClipRect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,5,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GameObject* self = (GameObject*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float w = ((float)  tolua_tonumber(tolua_S,4,0));
  float h = ((float)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setClipRect'",NULL);
#endif
 {
  self->setClipRect(x,y,w,h);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setClipRect'.",&tolua_err);
 return 0;
#endif
}

/* method: getLayerID of class  GameObject */
static int tolua_Aztec_Lua_Bind_GameObject_getLayerID00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GameObject* self = (GameObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getLayerID'",NULL);
#endif
 {
  unsigned int tolua_ret = (unsigned int)  self->getLayerID();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getLayerID'.",&tolua_err);
 return 0;
#endif
}

/* method: getLayer of class  GameObject */
static int tolua_Aztec_Lua_Bind_GameObject_getLayer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GameObject* self = (GameObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getLayer'",NULL);
#endif
 {
  GameObject* tolua_ret = (GameObject*)  self->getLayer();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"GameObject");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getLayer'.",&tolua_err);
 return 0;
#endif
}

/* method: isLayer of class  GameObject */
static int tolua_Aztec_Lua_Bind_GameObject_isLayer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GameObject* self = (GameObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isLayer'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->isLayer();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isLayer'.",&tolua_err);
 return 0;
#endif
}

/* method: setProperty of class  GameObject */
static int tolua_Aztec_Lua_Bind_GameObject_setProperty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GameObject* self = (GameObject*)  tolua_tousertype(tolua_S,1,0);
  const char* property = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setProperty'",NULL);
#endif
 {
  const char* tolua_ret = (const char*)  self->setProperty(property);
 tolua_pushstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setProperty'.",&tolua_err);
 return 0;
#endif
}

/* method: setProperty of class  GameObject */
static int tolua_Aztec_Lua_Bind_GameObject_setProperty01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isstring(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  GameObject* self = (GameObject*)  tolua_tousertype(tolua_S,1,0);
  const char* property = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* value = ((const char*)  tolua_tostring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setProperty'",NULL);
#endif
 {
  const char* tolua_ret = (const char*)  self->setProperty(property,value);
 tolua_pushstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
tolua_lerror:
 return tolua_Aztec_Lua_Bind_GameObject_setProperty00(tolua_S);
}

/* method: getProperty of class  GameObject */
static int tolua_Aztec_Lua_Bind_GameObject_getProperty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GameObject* self = (GameObject*)  tolua_tousertype(tolua_S,1,0);
  const char* property = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getProperty'",NULL);
#endif
 {
  const char* tolua_ret = (const char*)  self->getProperty(property);
 tolua_pushstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getProperty'.",&tolua_err);
 return 0;
#endif
}

/* method: removeProperty of class  GameObject */
static int tolua_Aztec_Lua_Bind_GameObject_removeProperty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GameObject* self = (GameObject*)  tolua_tousertype(tolua_S,1,0);
  const char* property = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeProperty'",NULL);
#endif
 {
  self->removeProperty(property);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeProperty'.",&tolua_err);
 return 0;
#endif
}

/* method: clearProperties of class  GameObject */
static int tolua_Aztec_Lua_Bind_GameObject_clearProperties00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GameObject* self = (GameObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'clearProperties'",NULL);
#endif
 {
  self->clearProperties();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'clearProperties'.",&tolua_err);
 return 0;
#endif
}

/* method: propertyAt of class  GameObject */
static int tolua_Aztec_Lua_Bind_GameObject_propertyAt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GameObject* self = (GameObject*)  tolua_tousertype(tolua_S,1,0);
  unsigned int index = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'propertyAt'",NULL);
#endif
 {
  const char* tolua_ret = (const char*)  self->propertyAt(index);
 tolua_pushstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'propertyAt'.",&tolua_err);
 return 0;
#endif
}

/* method: getPropertyName of class  GameObject */
static int tolua_Aztec_Lua_Bind_GameObject_getPropertyName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GameObject* self = (GameObject*)  tolua_tousertype(tolua_S,1,0);
  unsigned int index = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPropertyName'",NULL);
#endif
 {
  const char* tolua_ret = (const char*)  self->getPropertyName(index);
 tolua_pushstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPropertyName'.",&tolua_err);
 return 0;
#endif
}

/* method: hasProperty of class  GameObject */
static int tolua_Aztec_Lua_Bind_GameObject_hasProperty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GameObject* self = (GameObject*)  tolua_tousertype(tolua_S,1,0);
  const char* property = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'hasProperty'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->hasProperty(property);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'hasProperty'.",&tolua_err);
 return 0;
#endif
}

/* method: getPropertyCount of class  GameObject */
static int tolua_Aztec_Lua_Bind_GameObject_getPropertyCount00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GameObject* self = (GameObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPropertyCount'",NULL);
#endif
 {
  unsigned int tolua_ret = (unsigned int)  self->getPropertyCount();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPropertyCount'.",&tolua_err);
 return 0;
#endif
}

/* method: getGameState of class  GameObject */
static int tolua_Aztec_Lua_Bind_GameObject_getGameState00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GameObject* self = (GameObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getGameState'",NULL);
#endif
 {
  GameStateController* tolua_ret = (GameStateController*)  self->getGameState();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"GameStateController");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getGameState'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  Text */
static int tolua_Aztec_Lua_Bind_Text_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Text",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Text* tolua_ret = (Text*)  new Text();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Text");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  Text */
static int tolua_Aztec_Lua_Bind_Text_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Text",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isstring(tolua_S,5,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,6,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  int r = ((int)  tolua_tonumber(tolua_S,2,0));
  int g = ((int)  tolua_tonumber(tolua_S,3,0));
  int b = ((int)  tolua_tonumber(tolua_S,4,0));
  char* fontPath = ((char*)  tolua_tostring(tolua_S,5,0));
  int fontSize = ((int)  tolua_tonumber(tolua_S,6,0));
 {
  Text* tolua_ret = (Text*)  new Text(r,g,b,fontPath,fontSize);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Text");
 }
 }
 return 1;
tolua_lerror:
 return tolua_Aztec_Lua_Bind_Text_new00(tolua_S);
}

/* method: setText of class  Text */
static int tolua_Aztec_Lua_Bind_Text_setText00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Text",0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Text* self = (Text*)  tolua_tousertype(tolua_S,1,0);
  char* text = ((char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setText'",NULL);
#endif
 {
  self->setText(text);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setText'.",&tolua_err);
 return 0;
#endif
}

/* method: getText of class  Text */
static int tolua_Aztec_Lua_Bind_Text_getText00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Text",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Text* self = (Text*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getText'",NULL);
#endif
 {
  char* tolua_ret = (char*)  self->getText();
 tolua_pushstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getText'.",&tolua_err);
 return 0;
#endif
}

/* method: setColor of class  Text */
static int tolua_Aztec_Lua_Bind_Text_setColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Text",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Text* self = (Text*)  tolua_tousertype(tolua_S,1,0);
  int r = ((int)  tolua_tonumber(tolua_S,2,0));
  int g = ((int)  tolua_tonumber(tolua_S,3,0));
  int b = ((int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setColor'",NULL);
#endif
 {
  self->setColor(r,g,b);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setColor'.",&tolua_err);
 return 0;
#endif
}

/* method: setDimension of class  Text */
static int tolua_Aztec_Lua_Bind_Text_setDimension00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Text",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Text* self = (Text*)  tolua_tousertype(tolua_S,1,0);
  float w = ((float)  tolua_tonumber(tolua_S,2,0));
  float h = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setDimension'",NULL);
#endif
 {
  self->setDimension(w,h);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setDimension'.",&tolua_err);
 return 0;
#endif
}

/* method: selectByClick of class  Text */
static int tolua_Aztec_Lua_Bind_Text_selectByClick00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Text",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Text* self = (Text*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'selectByClick'",NULL);
#endif
 {
  self->selectByClick(x,y);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'selectByClick'.",&tolua_err);
 return 0;
#endif
}

/* method: setCursorPosition of class  Text */
static int tolua_Aztec_Lua_Bind_Text_setCursorPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Text",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Text* self = (Text*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setCursorPosition'",NULL);
#endif
 {
  self->setCursorPosition(i);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setCursorPosition'.",&tolua_err);
 return 0;
#endif
}

/* method: getCursorPosition of class  Text */
static int tolua_Aztec_Lua_Bind_Text_getCursorPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Text",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Text* self = (Text*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getCursorPosition'",NULL);
#endif
 {
  int tolua_ret = (int)  self->getCursorPosition();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getCursorPosition'.",&tolua_err);
 return 0;
#endif
}

/* method: getHeight of class  Text */
static int tolua_Aztec_Lua_Bind_Text_getHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Text",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Text* self = (Text*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getHeight'",NULL);
#endif
 {
  float tolua_ret = (float)  self->getHeight();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getHeight'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  Frame */
static int tolua_Aztec_Lua_Bind_Frame_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Frame",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  double interval = ((double)  tolua_tonumber(tolua_S,4,0));
 {
  Frame* tolua_ret = (Frame*)  new Frame(x,y,interval);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Frame");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  Frame */
static int tolua_Aztec_Lua_Bind_Frame_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Frame",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isboolean(tolua_S,5,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  double interval = ((double)  tolua_tonumber(tolua_S,4,0));
  bool flipped = ((bool)  tolua_toboolean(tolua_S,5,0));
 {
  Frame* tolua_ret = (Frame*)  new Frame(x,y,interval,flipped);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Frame");
 }
 }
 return 1;
tolua_lerror:
 return tolua_Aztec_Lua_Bind_Frame_new00(tolua_S);
}

/* method: new of class  Frame */
static int tolua_Aztec_Lua_Bind_Frame_new02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Frame",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isboolean(tolua_S,5,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,6,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  double interval = ((double)  tolua_tonumber(tolua_S,4,0));
  bool flipped = ((bool)  tolua_toboolean(tolua_S,5,0));
  float rotation = ((float)  tolua_tonumber(tolua_S,6,0));
 {
  Frame* tolua_ret = (Frame*)  new Frame(x,y,interval,flipped,rotation);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Frame");
 }
 }
 return 1;
tolua_lerror:
 return tolua_Aztec_Lua_Bind_Frame_new01(tolua_S);
}

/* get function: Loop of class  Animation */
static int tolua_get_Animation_Animation_Loop(lua_State* tolua_S)
{
  Animation* self = (Animation*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Loop'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->Loop);
 return 1;
}

/* set function: Loop of class  Animation */
static int tolua_set_Animation_Animation_Loop(lua_State* tolua_S)
{
  Animation* self = (Animation*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Loop'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Loop = ((bool)  tolua_toboolean(tolua_S,2,0));
 return 0;
}

/* get function: Finished of class  Animation */
static int tolua_get_Animation_Animation_Finished(lua_State* tolua_S)
{
  Animation* self = (Animation*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Finished'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->Finished);
 return 1;
}

/* set function: Finished of class  Animation */
static int tolua_set_Animation_Animation_Finished(lua_State* tolua_S)
{
  Animation* self = (Animation*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Finished'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Finished = ((bool)  tolua_toboolean(tolua_S,2,0));
 return 0;
}

/* get function: Started of class  Animation */
static int tolua_get_Animation_Animation_Started(lua_State* tolua_S)
{
  Animation* self = (Animation*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Started'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->Started);
 return 1;
}

/* set function: Started of class  Animation */
static int tolua_set_Animation_Animation_Started(lua_State* tolua_S)
{
  Animation* self = (Animation*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Started'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Started = ((bool)  tolua_toboolean(tolua_S,2,0));
 return 0;
}

/* method: getName of class  Animation */
static int tolua_Aztec_Lua_Bind_Animation_getName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Animation",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Animation* self = (Animation*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getName'",NULL);
#endif
 {
  char* tolua_ret = (char*)  self->getName();
 tolua_pushstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getName'.",&tolua_err);
 return 0;
#endif
}

/* method: setFrame of class  Animation */
static int tolua_Aztec_Lua_Bind_Animation_setFrame00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Animation",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Animation* self = (Animation*)  tolua_tousertype(tolua_S,1,0);
  int framenumber = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setFrame'",NULL);
#endif
 {
  Frame* tolua_ret = (Frame*)  self->setFrame(framenumber);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Frame");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setFrame'.",&tolua_err);
 return 0;
#endif
}

/* method: getCurrentFrame of class  Animation */
static int tolua_Aztec_Lua_Bind_Animation_getCurrentFrame00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Animation",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Animation* self = (Animation*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getCurrentFrame'",NULL);
#endif
 {
  Frame* tolua_ret = (Frame*)  self->getCurrentFrame();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Frame");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getCurrentFrame'.",&tolua_err);
 return 0;
#endif
}

/* method: addFrame of class  Animation */
static int tolua_Aztec_Lua_Bind_Animation_addFrame00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Animation",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Animation* self = (Animation*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  double interval = ((double)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addFrame'",NULL);
#endif
 {
  Frame* tolua_ret = (Frame*)  self->addFrame(x,y,interval);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Frame");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addFrame'.",&tolua_err);
 return 0;
#endif
}

/* method: addFrame of class  Animation */
static int tolua_Aztec_Lua_Bind_Animation_addFrame01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Animation",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isboolean(tolua_S,5,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Animation* self = (Animation*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  double interval = ((double)  tolua_tonumber(tolua_S,4,0));
  bool flipped = ((bool)  tolua_toboolean(tolua_S,5,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addFrame'",NULL);
#endif
 {
  Frame* tolua_ret = (Frame*)  self->addFrame(x,y,interval,flipped);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Frame");
 }
 }
 return 1;
tolua_lerror:
 return tolua_Aztec_Lua_Bind_Animation_addFrame00(tolua_S);
}

/* method: addFrame of class  Animation */
static int tolua_Aztec_Lua_Bind_Animation_addFrame02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Animation",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isboolean(tolua_S,5,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,6,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Animation* self = (Animation*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  double interval = ((double)  tolua_tonumber(tolua_S,4,0));
  bool flipped = ((bool)  tolua_toboolean(tolua_S,5,0));
  float rotation = ((float)  tolua_tonumber(tolua_S,6,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addFrame'",NULL);
#endif
 {
  Frame* tolua_ret = (Frame*)  self->addFrame(x,y,interval,flipped,rotation);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Frame");
 }
 }
 return 1;
tolua_lerror:
 return tolua_Aztec_Lua_Bind_Animation_addFrame01(tolua_S);
}

/* method: addFrame of class  Animation */
static int tolua_Aztec_Lua_Bind_Animation_addFrame03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Animation",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"Frame",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Animation* self = (Animation*)  tolua_tousertype(tolua_S,1,0);
  Frame* frame = ((Frame*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addFrame'",NULL);
#endif
 {
  Frame* tolua_ret = (Frame*)  self->addFrame(frame);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Frame");
 }
 }
 return 1;
tolua_lerror:
 return tolua_Aztec_Lua_Bind_Animation_addFrame02(tolua_S);
}

/* method: addHorizontalSequence of class  Animation */
static int tolua_Aztec_Lua_Bind_Animation_addHorizontalSequence00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Animation",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,5,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Animation* self = (Animation*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  int qtd = ((int)  tolua_tonumber(tolua_S,4,0));
  double duration = ((double)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addHorizontalSequence'",NULL);
#endif
 {
  self->addHorizontalSequence(x,y,qtd,duration);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addHorizontalSequence'.",&tolua_err);
 return 0;
#endif
}

/* method: addVerticalSequence of class  Animation */
static int tolua_Aztec_Lua_Bind_Animation_addVerticalSequence00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Animation",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,5,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Animation* self = (Animation*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  int qtd = ((int)  tolua_tonumber(tolua_S,4,0));
  double duration = ((double)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addVerticalSequence'",NULL);
#endif
 {
  self->addVerticalSequence(x,y,qtd,duration);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addVerticalSequence'.",&tolua_err);
 return 0;
#endif
}

/* method: deleteAllFrames of class  Animation */
static int tolua_Aztec_Lua_Bind_Animation_deleteAllFrames00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Animation",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Animation* self = (Animation*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'deleteAllFrames'",NULL);
#endif
 {
  self->deleteAllFrames();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'deleteAllFrames'.",&tolua_err);
 return 0;
#endif
}

/* method: setFrameInterval of class  Animation */
static int tolua_Aztec_Lua_Bind_Animation_setFrameInterval00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Animation",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Animation* self = (Animation*)  tolua_tousertype(tolua_S,1,0);
  double interval = ((double)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setFrameInterval'",NULL);
#endif
 {
  self->setFrameInterval(interval);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setFrameInterval'.",&tolua_err);
 return 0;
#endif
}

/* method: getTarget of class  Sensor */
static int tolua_Aztec_Lua_Bind_Sensor_getTarget00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Sensor",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Sensor* self = (Sensor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTarget'",NULL);
#endif
 {
  GameObject* tolua_ret = (GameObject*)  self->getTarget();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"GameObject");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getTarget'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  Sensor */
static int tolua_Aztec_Lua_Bind_Sensor_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Sensor",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,5,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float w = ((float)  tolua_tonumber(tolua_S,4,0));
  float h = ((float)  tolua_tonumber(tolua_S,5,0));
 {
  Sensor* tolua_ret = (Sensor*)  new Sensor(x,y,w,h);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Sensor");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  Sensor */
static int tolua_Aztec_Lua_Bind_Sensor_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Sensor",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  float w = ((float)  tolua_tonumber(tolua_S,2,0));
  float h = ((float)  tolua_tonumber(tolua_S,3,0));
 {
  Sensor* tolua_ret = (Sensor*)  new Sensor(w,h);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Sensor");
 }
 }
 return 1;
tolua_lerror:
 return tolua_Aztec_Lua_Bind_Sensor_new00(tolua_S);
}

/* method: new of class  Sensor */
static int tolua_Aztec_Lua_Bind_Sensor_new02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Sensor",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float radius = ((float)  tolua_tonumber(tolua_S,4,0));
 {
  Sensor* tolua_ret = (Sensor*)  new Sensor(x,y,radius);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Sensor");
 }
 }
 return 1;
tolua_lerror:
 return tolua_Aztec_Lua_Bind_Sensor_new01(tolua_S);
}

/* method: new of class  Sensor */
static int tolua_Aztec_Lua_Bind_Sensor_new03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Sensor",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  float radius = ((float)  tolua_tonumber(tolua_S,2,0));
 {
  Sensor* tolua_ret = (Sensor*)  new Sensor(radius);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Sensor");
 }
 }
 return 1;
tolua_lerror:
 return tolua_Aztec_Lua_Bind_Sensor_new02(tolua_S);
}

/* method: new of class  Sensor */
static int tolua_Aztec_Lua_Bind_Sensor_new04(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Sensor",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"PointList2D",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  PointList2D point_list = *((PointList2D*)  tolua_tousertype(tolua_S,2,0));
 {
  Sensor* tolua_ret = (Sensor*)  new Sensor(point_list);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Sensor");
 }
 }
 return 1;
tolua_lerror:
 return tolua_Aztec_Lua_Bind_Sensor_new03(tolua_S);
}

/* method: createFixture of class  Sensor */
static int tolua_Aztec_Lua_Bind_Sensor_createFixture00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Sensor",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Sensor* self = (Sensor*)  tolua_tousertype(tolua_S,1,0);
  float radius = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'createFixture'",NULL);
#endif
 {
  self->createFixture(radius);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'createFixture'.",&tolua_err);
 return 0;
#endif
}

/* method: createFixture of class  Sensor */
static int tolua_Aztec_Lua_Bind_Sensor_createFixture01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Sensor",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Sensor* self = (Sensor*)  tolua_tousertype(tolua_S,1,0);
  float w = ((float)  tolua_tonumber(tolua_S,2,0));
  float h = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'createFixture'",NULL);
#endif
 {
  self->createFixture(w,h);
 }
 }
 return 0;
tolua_lerror:
 return tolua_Aztec_Lua_Bind_Sensor_createFixture00(tolua_S);
}

/* method: createFixture of class  Sensor */
static int tolua_Aztec_Lua_Bind_Sensor_createFixture02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Sensor",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"PointList2D",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Sensor* self = (Sensor*)  tolua_tousertype(tolua_S,1,0);
  PointList2D point_list = *((PointList2D*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'createFixture'",NULL);
#endif
 {
  self->createFixture(point_list);
 }
 }
 return 0;
tolua_lerror:
 return tolua_Aztec_Lua_Bind_Sensor_createFixture01(tolua_S);
}

/* method: delete of class  Sensor */
static int tolua_Aztec_Lua_Bind_Sensor_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Sensor",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Sensor* self = (Sensor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
 tolua_release(tolua_S,self);
 delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* method: clear of class  PropertyList */
static int tolua_Aztec_Lua_Bind_PropertyList_clear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"PropertyList",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  PropertyList* self = (PropertyList*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'clear'",NULL);
#endif
 {
  self->clear();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'clear'.",&tolua_err);
 return 0;
#endif
}

/* method: add of class  PropertyList */
static int tolua_Aztec_Lua_Bind_PropertyList_add00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"PropertyList",0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isstring(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  PropertyList* self = (PropertyList*)  tolua_tousertype(tolua_S,1,0);
  const char* property = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* value = ((const char*)  tolua_tostring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'add'",NULL);
#endif
 {
  const char* tolua_ret = (const char*)  self->add(property,value);
 tolua_pushstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'add'.",&tolua_err);
 return 0;
#endif
}

/* method: get of class  PropertyList */
static int tolua_Aztec_Lua_Bind_PropertyList_get00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"PropertyList",0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  PropertyList* self = (PropertyList*)  tolua_tousertype(tolua_S,1,0);
  const char* property = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'get'",NULL);
#endif
 {
  const char* tolua_ret = (const char*)  self->get(property);
 tolua_pushstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'get'.",&tolua_err);
 return 0;
#endif
}

/* method: at of class  PropertyList */
static int tolua_Aztec_Lua_Bind_PropertyList_at00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"PropertyList",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  PropertyList* self = (PropertyList*)  tolua_tousertype(tolua_S,1,0);
  unsigned int index = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'at'",NULL);
#endif
 {
  const char* tolua_ret = (const char*)  self->at(index);
 tolua_pushstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'at'.",&tolua_err);
 return 0;
#endif
}

/* method: getName of class  PropertyList */
static int tolua_Aztec_Lua_Bind_PropertyList_getName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"PropertyList",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  PropertyList* self = (PropertyList*)  tolua_tousertype(tolua_S,1,0);
  unsigned int index = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getName'",NULL);
#endif
 {
  const char* tolua_ret = (const char*)  self->getName(index);
 tolua_pushstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getName'.",&tolua_err);
 return 0;
#endif
}

/* method: getIndex of class  PropertyList */
static int tolua_Aztec_Lua_Bind_PropertyList_getIndex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"PropertyList",0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  PropertyList* self = (PropertyList*)  tolua_tousertype(tolua_S,1,0);
  const char* property = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getIndex'",NULL);
#endif
 {
  int tolua_ret = (int)  self->getIndex(property);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getIndex'.",&tolua_err);
 return 0;
#endif
}

/* method: getValueIndex of class  PropertyList */
static int tolua_Aztec_Lua_Bind_PropertyList_getValueIndex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"PropertyList",0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  PropertyList* self = (PropertyList*)  tolua_tousertype(tolua_S,1,0);
  const char* value = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getValueIndex'",NULL);
#endif
 {
  int tolua_ret = (int)  self->getValueIndex(value);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getValueIndex'.",&tolua_err);
 return 0;
#endif
}

/* method: getValueIndex of class  PropertyList */
static int tolua_Aztec_Lua_Bind_PropertyList_getValueIndex01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"PropertyList",0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  PropertyList* self = (PropertyList*)  tolua_tousertype(tolua_S,1,0);
  const char* value = ((const char*)  tolua_tostring(tolua_S,2,0));
  unsigned int n = ((unsigned int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getValueIndex'",NULL);
#endif
 {
  int tolua_ret = (int)  self->getValueIndex(value,n);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
tolua_lerror:
 return tolua_Aztec_Lua_Bind_PropertyList_getValueIndex00(tolua_S);
}

/* method: getSize of class  PropertyList */
static int tolua_Aztec_Lua_Bind_PropertyList_getSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"PropertyList",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  PropertyList* self = (PropertyList*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getSize'",NULL);
#endif
 {
  int tolua_ret = (int)  self->getSize();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getSize'.",&tolua_err);
 return 0;
#endif
}

/* method: set of class  PropertyList */
static int tolua_Aztec_Lua_Bind_PropertyList_set00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"PropertyList",0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isstring(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  PropertyList* self = (PropertyList*)  tolua_tousertype(tolua_S,1,0);
  const char* property = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* value = ((const char*)  tolua_tostring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set'",NULL);
#endif
 {
  const char* tolua_ret = (const char*)  self->set(property,value);
 tolua_pushstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set'.",&tolua_err);
 return 0;
#endif
}

/* method: remove of class  PropertyList */
static int tolua_Aztec_Lua_Bind_PropertyList_remove00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"PropertyList",0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  PropertyList* self = (PropertyList*)  tolua_tousertype(tolua_S,1,0);
  const char* property = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'remove'",NULL);
#endif
 {
  self->remove(property);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'remove'.",&tolua_err);
 return 0;
#endif
}

/* method: has of class  PropertyList */
static int tolua_Aztec_Lua_Bind_PropertyList_has00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"PropertyList",0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  PropertyList* self = (PropertyList*)  tolua_tousertype(tolua_S,1,0);
  const char* property = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'has'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->has(property);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'has'.",&tolua_err);
 return 0;
#endif
}

/* method: hasValue of class  PropertyList */
static int tolua_Aztec_Lua_Bind_PropertyList_hasValue00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"PropertyList",0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  PropertyList* self = (PropertyList*)  tolua_tousertype(tolua_S,1,0);
  const char* value = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'hasValue'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->hasValue(value);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'hasValue'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  PropertyList */
static int tolua_Aztec_Lua_Bind_PropertyList_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"PropertyList",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  PropertyList* tolua_ret = (PropertyList*)  new PropertyList();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"PropertyList");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  PropertyList */
static int tolua_Aztec_Lua_Bind_PropertyList_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"PropertyList",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  PropertyList* self = (PropertyList*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
 tolua_release(tolua_S,self);
 delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  AutoSensor */
static int tolua_Aztec_Lua_Bind_AutoSensor_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"AutoSensor",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,5,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float w = ((float)  tolua_tonumber(tolua_S,4,0));
  float h = ((float)  tolua_tonumber(tolua_S,5,0));
 {
  AutoSensor* tolua_ret = (AutoSensor*)  new AutoSensor(x,y,w,h);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"AutoSensor");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  AutoSensor */
static int tolua_Aztec_Lua_Bind_AutoSensor_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"AutoSensor",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  float w = ((float)  tolua_tonumber(tolua_S,2,0));
  float h = ((float)  tolua_tonumber(tolua_S,3,0));
 {
  AutoSensor* tolua_ret = (AutoSensor*)  new AutoSensor(w,h);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"AutoSensor");
 }
 }
 return 1;
tolua_lerror:
 return tolua_Aztec_Lua_Bind_AutoSensor_new00(tolua_S);
}

/* method: new of class  AutoSensor */
static int tolua_Aztec_Lua_Bind_AutoSensor_new02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"AutoSensor",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float radius = ((float)  tolua_tonumber(tolua_S,4,0));
 {
  AutoSensor* tolua_ret = (AutoSensor*)  new AutoSensor(x,y,radius);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"AutoSensor");
 }
 }
 return 1;
tolua_lerror:
 return tolua_Aztec_Lua_Bind_AutoSensor_new01(tolua_S);
}

/* method: new of class  AutoSensor */
static int tolua_Aztec_Lua_Bind_AutoSensor_new03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"AutoSensor",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  float radius = ((float)  tolua_tonumber(tolua_S,2,0));
 {
  AutoSensor* tolua_ret = (AutoSensor*)  new AutoSensor(radius);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"AutoSensor");
 }
 }
 return 1;
tolua_lerror:
 return tolua_Aztec_Lua_Bind_AutoSensor_new02(tolua_S);
}

/* method: delete of class  AutoSensor */
static int tolua_Aztec_Lua_Bind_AutoSensor_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"AutoSensor",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  AutoSensor* self = (AutoSensor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
 tolua_release(tolua_S,self);
 delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* method: SetUniform of class  Shader */
static int tolua_Aztec_Lua_Bind_Shader_SetUniform00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Shader",0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Shader* self = (Shader*)  tolua_tousertype(tolua_S,1,0);
  char* name = ((char*)  tolua_tostring(tolua_S,2,0));
  float x = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetUniform'",NULL);
#endif
 {
  self->SetUniform(name,x);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetUniform'.",&tolua_err);
 return 0;
#endif
}

/* method: SetUniform of class  Shader */
static int tolua_Aztec_Lua_Bind_Shader_SetUniform01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Shader",0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Shader* self = (Shader*)  tolua_tousertype(tolua_S,1,0);
  char* name = ((char*)  tolua_tostring(tolua_S,2,0));
  float x = ((float)  tolua_tonumber(tolua_S,3,0));
  float y = ((float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetUniform'",NULL);
#endif
 {
  self->SetUniform(name,x,y);
 }
 }
 return 0;
tolua_lerror:
 return tolua_Aztec_Lua_Bind_Shader_SetUniform00(tolua_S);
}

/* method: SetUniform of class  Shader */
static int tolua_Aztec_Lua_Bind_Shader_SetUniform02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Shader",0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,5,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Shader* self = (Shader*)  tolua_tousertype(tolua_S,1,0);
  char* name = ((char*)  tolua_tostring(tolua_S,2,0));
  float x = ((float)  tolua_tonumber(tolua_S,3,0));
  float y = ((float)  tolua_tonumber(tolua_S,4,0));
  float z = ((float)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetUniform'",NULL);
#endif
 {
  self->SetUniform(name,x,y,z);
 }
 }
 return 0;
tolua_lerror:
 return tolua_Aztec_Lua_Bind_Shader_SetUniform01(tolua_S);
}

/* method: SetUniform of class  Shader */
static int tolua_Aztec_Lua_Bind_Shader_SetUniform03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Shader",0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,5,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,6,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Shader* self = (Shader*)  tolua_tousertype(tolua_S,1,0);
  char* name = ((char*)  tolua_tostring(tolua_S,2,0));
  float x = ((float)  tolua_tonumber(tolua_S,3,0));
  float y = ((float)  tolua_tonumber(tolua_S,4,0));
  float z = ((float)  tolua_tonumber(tolua_S,5,0));
  float w = ((float)  tolua_tonumber(tolua_S,6,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetUniform'",NULL);
#endif
 {
  self->SetUniform(name,x,y,z,w);
 }
 }
 return 0;
tolua_lerror:
 return tolua_Aztec_Lua_Bind_Shader_SetUniform02(tolua_S);
}

/* method: SetUniformI of class  Shader */
static int tolua_Aztec_Lua_Bind_Shader_SetUniformI00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Shader",0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Shader* self = (Shader*)  tolua_tousertype(tolua_S,1,0);
  char* name = ((char*)  tolua_tostring(tolua_S,2,0));
  int x = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetUniformI'",NULL);
#endif
 {
  self->SetUniformI(name,x);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetUniformI'.",&tolua_err);
 return 0;
#endif
}

/* method: SetUniformI of class  Shader */
static int tolua_Aztec_Lua_Bind_Shader_SetUniformI01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Shader",0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Shader* self = (Shader*)  tolua_tousertype(tolua_S,1,0);
  char* name = ((char*)  tolua_tostring(tolua_S,2,0));
  int x = ((int)  tolua_tonumber(tolua_S,3,0));
  int y = ((int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetUniformI'",NULL);
#endif
 {
  self->SetUniformI(name,x,y);
 }
 }
 return 0;
tolua_lerror:
 return tolua_Aztec_Lua_Bind_Shader_SetUniformI00(tolua_S);
}

/* method: SetUniformI of class  Shader */
static int tolua_Aztec_Lua_Bind_Shader_SetUniformI02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Shader",0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,5,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Shader* self = (Shader*)  tolua_tousertype(tolua_S,1,0);
  char* name = ((char*)  tolua_tostring(tolua_S,2,0));
  int x = ((int)  tolua_tonumber(tolua_S,3,0));
  int y = ((int)  tolua_tonumber(tolua_S,4,0));
  int z = ((int)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetUniformI'",NULL);
#endif
 {
  self->SetUniformI(name,x,y,z);
 }
 }
 return 0;
tolua_lerror:
 return tolua_Aztec_Lua_Bind_Shader_SetUniformI01(tolua_S);
}

/* method: SetUniformI of class  Shader */
static int tolua_Aztec_Lua_Bind_Shader_SetUniformI03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Shader",0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,5,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,6,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Shader* self = (Shader*)  tolua_tousertype(tolua_S,1,0);
  char* name = ((char*)  tolua_tostring(tolua_S,2,0));
  int x = ((int)  tolua_tonumber(tolua_S,3,0));
  int y = ((int)  tolua_tonumber(tolua_S,4,0));
  int z = ((int)  tolua_tonumber(tolua_S,5,0));
  int w = ((int)  tolua_tonumber(tolua_S,6,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetUniformI'",NULL);
#endif
 {
  self->SetUniformI(name,x,y,z,w);
 }
 }
 return 0;
tolua_lerror:
 return tolua_Aztec_Lua_Bind_Shader_SetUniformI02(tolua_S);
}

/* method: SetUniformMatrix of class  Shader */
static int tolua_Aztec_Lua_Bind_Shader_SetUniformMatrix00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Shader",0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,5,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,6,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Shader* self = (Shader*)  tolua_tousertype(tolua_S,1,0);
  char* name = ((char*)  tolua_tostring(tolua_S,2,0));
  int row = ((int)  tolua_tonumber(tolua_S,3,0));
  int col = ((int)  tolua_tonumber(tolua_S,4,0));
  int count = ((int)  tolua_tonumber(tolua_S,5,0));
  float v = ((float)  tolua_tonumber(tolua_S,6,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetUniformMatrix'",NULL);
#endif
 {
  self->SetUniformMatrix(name,row,col,count,&v);
 tolua_pushnumber(tolua_S,(lua_Number)v);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetUniformMatrix'.",&tolua_err);
 return 0;
#endif
}

/* method: createFromFiles of class  Shader */
static int tolua_Aztec_Lua_Bind_Shader_createFromFiles00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Shader",0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isstring(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  char* vextexSourceFile = ((char*)  tolua_tostring(tolua_S,2,0));
  char* fragmentSourceFile = ((char*)  tolua_tostring(tolua_S,3,0));
 {
  Shader* tolua_ret = (Shader*)  Shader::createFromFiles(vextexSourceFile,fragmentSourceFile);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Shader");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'createFromFiles'.",&tolua_err);
 return 0;
#endif
}

/* method: createFromSource of class  Shader */
static int tolua_Aztec_Lua_Bind_Shader_createFromSource00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Shader",0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isstring(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  char* vextexSourceCode = ((char*)  tolua_tostring(tolua_S,2,0));
  char* fragmentSourceCode = ((char*)  tolua_tostring(tolua_S,3,0));
 {
  Shader* tolua_ret = (Shader*)  Shader::createFromSource(vextexSourceCode,fragmentSourceCode);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Shader");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'createFromSource'.",&tolua_err);
 return 0;
#endif
}

/* method: createDefaultShader of class  Shader */
static int tolua_Aztec_Lua_Bind_Shader_createDefaultShader00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Shader",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Shader* tolua_ret = (Shader*)  Shader::createDefaultShader();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Shader");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'createDefaultShader'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  Shader */
static int tolua_Aztec_Lua_Bind_Shader_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Shader",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Shader* self = (Shader*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
 tolua_release(tolua_S,self);
 delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  Sprite */
static int tolua_Aztec_Lua_Bind_Sprite_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Sprite",0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  char* filename = ((char*)  tolua_tostring(tolua_S,2,0));
 {
  Sprite* tolua_ret = (Sprite*)  new Sprite(filename);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Sprite");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  Sprite */
static int tolua_Aztec_Lua_Bind_Sprite_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Sprite",0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isboolean(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  char* filename = ((char*)  tolua_tostring(tolua_S,2,0));
  bool centerPivot = ((bool)  tolua_toboolean(tolua_S,3,0));
 {
  Sprite* tolua_ret = (Sprite*)  new Sprite(filename,centerPivot);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Sprite");
 }
 }
 return 1;
tolua_lerror:
 return tolua_Aztec_Lua_Bind_Sprite_new00(tolua_S);
}

/* method: new of class  Sprite */
static int tolua_Aztec_Lua_Bind_Sprite_new02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Sprite",0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,5,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  char* filename = ((char*)  tolua_tostring(tolua_S,2,0));
  int animFrameCount = ((int)  tolua_tonumber(tolua_S,3,0));
  float animFrameWidth = ((float)  tolua_tonumber(tolua_S,4,0));
  float animFrameHeight = ((float)  tolua_tonumber(tolua_S,5,0));
 {
  Sprite* tolua_ret = (Sprite*)  new Sprite(filename,animFrameCount,animFrameWidth,animFrameHeight);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Sprite");
 }
 }
 return 1;
tolua_lerror:
 return tolua_Aztec_Lua_Bind_Sprite_new01(tolua_S);
}

/* method: new of class  Sprite */
static int tolua_Aztec_Lua_Bind_Sprite_new03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Sprite",0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,5,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  char* filename = ((char*)  tolua_tostring(tolua_S,2,0));
  int animFrameCount = ((int)  tolua_tonumber(tolua_S,3,0));
  float animFrameWidth = ((float)  tolua_tonumber(tolua_S,4,0));
  float animFrameHeight = ((float)  tolua_tonumber(tolua_S,5,0));
 {
  Sprite* tolua_ret = (Sprite*)  new Sprite(filename,animFrameCount,animFrameWidth,animFrameHeight);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Sprite");
 }
 }
 return 1;
tolua_lerror:
 return tolua_Aztec_Lua_Bind_Sprite_new02(tolua_S);
}

/* method: new of class  Sprite */
static int tolua_Aztec_Lua_Bind_Sprite_new04(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Sprite",0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,5,0,&tolua_err) || 
 !tolua_isboolean(tolua_S,6,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  char* filename = ((char*)  tolua_tostring(tolua_S,2,0));
  int animFrameCount = ((int)  tolua_tonumber(tolua_S,3,0));
  float animFrameWidth = ((float)  tolua_tonumber(tolua_S,4,0));
  float animFrameHeight = ((float)  tolua_tonumber(tolua_S,5,0));
  bool centerPivot = ((bool)  tolua_toboolean(tolua_S,6,0));
 {
  Sprite* tolua_ret = (Sprite*)  new Sprite(filename,animFrameCount,animFrameWidth,animFrameHeight,centerPivot);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Sprite");
 }
 }
 return 1;
tolua_lerror:
 return tolua_Aztec_Lua_Bind_Sprite_new03(tolua_S);
}

/* method: new of class  Sprite */
static int tolua_Aztec_Lua_Bind_Sprite_new05(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Sprite",0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  char* filename = ((char*)  tolua_tostring(tolua_S,2,0));
  float animFrameWidth = ((float)  tolua_tonumber(tolua_S,3,0));
  float animFrameHeight = ((float)  tolua_tonumber(tolua_S,4,0));
 {
  Sprite* tolua_ret = (Sprite*)  new Sprite(filename,animFrameWidth,animFrameHeight);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Sprite");
 }
 }
 return 1;
tolua_lerror:
 return tolua_Aztec_Lua_Bind_Sprite_new04(tolua_S);
}

/* method: new of class  Sprite */
static int tolua_Aztec_Lua_Bind_Sprite_new06(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Sprite",0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isboolean(tolua_S,5,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  char* filename = ((char*)  tolua_tostring(tolua_S,2,0));
  float animFrameWidth = ((float)  tolua_tonumber(tolua_S,3,0));
  float animFrameHeight = ((float)  tolua_tonumber(tolua_S,4,0));
  bool centerPivot = ((bool)  tolua_toboolean(tolua_S,5,0));
 {
  Sprite* tolua_ret = (Sprite*)  new Sprite(filename,animFrameWidth,animFrameHeight,centerPivot);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Sprite");
 }
 }
 return 1;
tolua_lerror:
 return tolua_Aztec_Lua_Bind_Sprite_new05(tolua_S);
}

/* method: setFlipped of class  Sprite */
static int tolua_Aztec_Lua_Bind_Sprite_setFlipped00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Sprite",0,&tolua_err) || 
 !tolua_isboolean(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Sprite* self = (Sprite*)  tolua_tousertype(tolua_S,1,0);
  bool flipped = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setFlipped'",NULL);
#endif
 {
  self->setFlipped(flipped);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setFlipped'.",&tolua_err);
 return 0;
#endif
}

/* method: setVerticalFlipped of class  Sprite */
static int tolua_Aztec_Lua_Bind_Sprite_setVerticalFlipped00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Sprite",0,&tolua_err) || 
 !tolua_isboolean(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Sprite* self = (Sprite*)  tolua_tousertype(tolua_S,1,0);
  bool verticalFlipped = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setVerticalFlipped'",NULL);
#endif
 {
  self->setVerticalFlipped(verticalFlipped);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setVerticalFlipped'.",&tolua_err);
 return 0;
#endif
}

/* method: getFlipped of class  Sprite */
static int tolua_Aztec_Lua_Bind_Sprite_getFlipped00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Sprite",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Sprite* self = (Sprite*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getFlipped'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->getFlipped();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getFlipped'.",&tolua_err);
 return 0;
#endif
}

/* method: getVerticalFlipped of class  Sprite */
static int tolua_Aztec_Lua_Bind_Sprite_getVerticalFlipped00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Sprite",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Sprite* self = (Sprite*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getVerticalFlipped'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->getVerticalFlipped();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getVerticalFlipped'.",&tolua_err);
 return 0;
#endif
}

/* method: setFrameInterval of class  Sprite */
static int tolua_Aztec_Lua_Bind_Sprite_setFrameInterval00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Sprite",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Sprite* self = (Sprite*)  tolua_tousertype(tolua_S,1,0);
  long interval = ((long)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setFrameInterval'",NULL);
#endif
 {
  self->setFrameInterval(interval);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setFrameInterval'.",&tolua_err);
 return 0;
#endif
}

/* method: getFrameInterval of class  Sprite */
static int tolua_Aztec_Lua_Bind_Sprite_getFrameInterval00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Sprite",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Sprite* self = (Sprite*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getFrameInterval'",NULL);
#endif
 {
  long tolua_ret = (long)  self->getFrameInterval();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getFrameInterval'.",&tolua_err);
 return 0;
#endif
}

/* method: pivotOnCenter of class  Sprite */
static int tolua_Aztec_Lua_Bind_Sprite_pivotOnCenter00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Sprite",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Sprite* self = (Sprite*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'pivotOnCenter'",NULL);
#endif
 {
  self->pivotOnCenter();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'pivotOnCenter'.",&tolua_err);
 return 0;
#endif
}

/* method: newAnimation of class  Sprite */
static int tolua_Aztec_Lua_Bind_Sprite_newAnimation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Sprite",0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Sprite* self = (Sprite*)  tolua_tousertype(tolua_S,1,0);
  char* name = ((char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'newAnimation'",NULL);
#endif
 {
  Animation* tolua_ret = (Animation*)  self->newAnimation(name);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Animation");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'newAnimation'.",&tolua_err);
 return 0;
#endif
}

/* method: removeAnimation of class  Sprite */
static int tolua_Aztec_Lua_Bind_Sprite_removeAnimation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Sprite",0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Sprite* self = (Sprite*)  tolua_tousertype(tolua_S,1,0);
  char* name = ((char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeAnimation'",NULL);
#endif
 {
  self->removeAnimation(name);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeAnimation'.",&tolua_err);
 return 0;
#endif
}

/* method: setAnimation of class  Sprite */
static int tolua_Aztec_Lua_Bind_Sprite_setAnimation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Sprite",0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Sprite* self = (Sprite*)  tolua_tousertype(tolua_S,1,0);
  char* name = ((char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setAnimation'",NULL);
#endif
 {
  Animation* tolua_ret = (Animation*)  self->setAnimation(name);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Animation");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setAnimation'.",&tolua_err);
 return 0;
#endif
}

/* method: setAnimation of class  Sprite */
static int tolua_Aztec_Lua_Bind_Sprite_setAnimation01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Sprite",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"Animation",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Sprite* self = (Sprite*)  tolua_tousertype(tolua_S,1,0);
  Animation* animation = ((Animation*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setAnimation'",NULL);
#endif
 {
  Animation* tolua_ret = (Animation*)  self->setAnimation(animation);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Animation");
 }
 }
 return 1;
tolua_lerror:
 return tolua_Aztec_Lua_Bind_Sprite_setAnimation00(tolua_S);
}

/* method: getCurrentAnimation of class  Sprite */
static int tolua_Aztec_Lua_Bind_Sprite_getCurrentAnimation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Sprite",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Sprite* self = (Sprite*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getCurrentAnimation'",NULL);
#endif
 {
  Animation* tolua_ret = (Animation*)  self->getCurrentAnimation();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Animation");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getCurrentAnimation'.",&tolua_err);
 return 0;
#endif
}

/* method: setShader of class  Sprite */
static int tolua_Aztec_Lua_Bind_Sprite_setShader00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Sprite",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"Shader",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Sprite* self = (Sprite*)  tolua_tousertype(tolua_S,1,0);
  Shader* shader = ((Shader*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setShader'",NULL);
#endif
 {
  Shader* tolua_ret = (Shader*)  self->setShader(shader);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Shader");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setShader'.",&tolua_err);
 return 0;
#endif
}

/* method: getShader of class  Sprite */
static int tolua_Aztec_Lua_Bind_Sprite_getShader00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Sprite",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Sprite* self = (Sprite*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getShader'",NULL);
#endif
 {
  Shader* tolua_ret = (Shader*)  self->getShader();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Shader");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getShader'.",&tolua_err);
 return 0;
#endif
}

/* method: getPlane of class  Sprite */
static int tolua_Aztec_Lua_Bind_Sprite_getPlane00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Sprite",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Sprite* self = (Sprite*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPlane'",NULL);
#endif
 {
  Plane* tolua_ret = (Plane*)  self->getPlane();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Plane");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPlane'.",&tolua_err);
 return 0;
#endif
}

/* method: createSensor of class  Sprite */
static int tolua_Aztec_Lua_Bind_Sprite_createSensor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Sprite",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Sprite* self = (Sprite*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'createSensor'",NULL);
#endif
 {
  self->createSensor();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'createSensor'.",&tolua_err);
 return 0;
#endif
}

/* method: createCircleSensor of class  Sprite */
static int tolua_Aztec_Lua_Bind_Sprite_createCircleSensor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Sprite",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Sprite* self = (Sprite*)  tolua_tousertype(tolua_S,1,0);
  float radius = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'createCircleSensor'",NULL);
#endif
 {
  self->createCircleSensor(radius);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'createCircleSensor'.",&tolua_err);
 return 0;
#endif
}

/* method: destroySensor of class  Sprite */
static int tolua_Aztec_Lua_Bind_Sprite_destroySensor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Sprite",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Sprite* self = (Sprite*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'destroySensor'",NULL);
#endif
 {
  self->destroySensor();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'destroySensor'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  SpriteSensor */
static int tolua_Aztec_Lua_Bind_SpriteSensor_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"SpriteSensor",0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  char* filename = ((char*)  tolua_tostring(tolua_S,2,0));
 {
  SpriteSensor* tolua_ret = (SpriteSensor*)  new SpriteSensor(filename);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"SpriteSensor");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  SpriteSensor */
static int tolua_Aztec_Lua_Bind_SpriteSensor_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"SpriteSensor",0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isboolean(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  char* filename = ((char*)  tolua_tostring(tolua_S,2,0));
  bool centerPivot = ((bool)  tolua_toboolean(tolua_S,3,0));
 {
  SpriteSensor* tolua_ret = (SpriteSensor*)  new SpriteSensor(filename,centerPivot);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"SpriteSensor");
 }
 }
 return 1;
tolua_lerror:
 return tolua_Aztec_Lua_Bind_SpriteSensor_new00(tolua_S);
}

/* method: new of class  SpriteSensor */
static int tolua_Aztec_Lua_Bind_SpriteSensor_new02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"SpriteSensor",0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,5,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  char* filename = ((char*)  tolua_tostring(tolua_S,2,0));
  int animFrameCount = ((int)  tolua_tonumber(tolua_S,3,0));
  float animFrameWidth = ((float)  tolua_tonumber(tolua_S,4,0));
  float animFrameHeight = ((float)  tolua_tonumber(tolua_S,5,0));
 {
  SpriteSensor* tolua_ret = (SpriteSensor*)  new SpriteSensor(filename,animFrameCount,animFrameWidth,animFrameHeight);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"SpriteSensor");
 }
 }
 return 1;
tolua_lerror:
 return tolua_Aztec_Lua_Bind_SpriteSensor_new01(tolua_S);
}

/* method: new of class  SpriteSensor */
static int tolua_Aztec_Lua_Bind_SpriteSensor_new03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"SpriteSensor",0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,5,0,&tolua_err) || 
 !tolua_isboolean(tolua_S,6,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  char* filename = ((char*)  tolua_tostring(tolua_S,2,0));
  int animFrameCount = ((int)  tolua_tonumber(tolua_S,3,0));
  float animFrameWidth = ((float)  tolua_tonumber(tolua_S,4,0));
  float animFrameHeight = ((float)  tolua_tonumber(tolua_S,5,0));
  bool centerPivot = ((bool)  tolua_toboolean(tolua_S,6,0));
 {
  SpriteSensor* tolua_ret = (SpriteSensor*)  new SpriteSensor(filename,animFrameCount,animFrameWidth,animFrameHeight,centerPivot);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"SpriteSensor");
 }
 }
 return 1;
tolua_lerror:
 return tolua_Aztec_Lua_Bind_SpriteSensor_new02(tolua_S);
}

/* method: new of class  SpriteSensor */
static int tolua_Aztec_Lua_Bind_SpriteSensor_new04(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"SpriteSensor",0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  char* filename = ((char*)  tolua_tostring(tolua_S,2,0));
  float animFrameWidth = ((float)  tolua_tonumber(tolua_S,3,0));
  float animFrameHeight = ((float)  tolua_tonumber(tolua_S,4,0));
 {
  SpriteSensor* tolua_ret = (SpriteSensor*)  new SpriteSensor(filename,animFrameWidth,animFrameHeight);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"SpriteSensor");
 }
 }
 return 1;
tolua_lerror:
 return tolua_Aztec_Lua_Bind_SpriteSensor_new03(tolua_S);
}

/* method: new of class  SpriteSensor */
static int tolua_Aztec_Lua_Bind_SpriteSensor_new05(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"SpriteSensor",0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isboolean(tolua_S,5,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  char* filename = ((char*)  tolua_tostring(tolua_S,2,0));
  float animFrameWidth = ((float)  tolua_tonumber(tolua_S,3,0));
  float animFrameHeight = ((float)  tolua_tonumber(tolua_S,4,0));
  bool centerPivot = ((bool)  tolua_toboolean(tolua_S,5,0));
 {
  SpriteSensor* tolua_ret = (SpriteSensor*)  new SpriteSensor(filename,animFrameWidth,animFrameHeight,centerPivot);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"SpriteSensor");
 }
 }
 return 1;
tolua_lerror:
 return tolua_Aztec_Lua_Bind_SpriteSensor_new04(tolua_S);
}

/* method: new of class  GameStateController */
static int tolua_Aztec_Lua_Bind_GameStateController_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"GameStateController",0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const char* tmx_path = ((const char*)  tolua_tostring(tolua_S,2,0));
 {
  GameStateController* tolua_ret = (GameStateController*)  new GameStateController(tmx_path);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"GameStateController");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  GameStateController */
static int tolua_Aztec_Lua_Bind_GameStateController_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"GameStateController",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
 {
  GameStateController* tolua_ret = (GameStateController*)  new GameStateController();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"GameStateController");
 }
 }
 return 1;
tolua_lerror:
 return tolua_Aztec_Lua_Bind_GameStateController_new00(tolua_S);
}

/* method: delete of class  GameStateController */
static int tolua_Aztec_Lua_Bind_GameStateController_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"GameStateController",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GameStateController* self = (GameStateController*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
 tolua_release(tolua_S,self);
 delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* method: load of class  GameStateController */
static int tolua_Aztec_Lua_Bind_GameStateController_load00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"GameStateController",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GameStateController* self = (GameStateController*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'load'",NULL);
#endif
 {
  self->load();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'load'.",&tolua_err);
 return 0;
#endif
}

/* method: queryProperty of class  GameStateController */
static int tolua_Aztec_Lua_Bind_GameStateController_queryProperty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"GameStateController",0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GameStateController* self = (GameStateController*)  tolua_tousertype(tolua_S,1,0);
  const char* property = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'queryProperty'",NULL);
#endif
 {
  GameObjectList* tolua_ret = (GameObjectList*)  self->queryProperty(property);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"GameObjectList");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'queryProperty'.",&tolua_err);
 return 0;
#endif
}

/* method: queryProperty of class  GameStateController */
static int tolua_Aztec_Lua_Bind_GameStateController_queryProperty01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"GameStateController",0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isstring(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  GameStateController* self = (GameStateController*)  tolua_tousertype(tolua_S,1,0);
  const char* property = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* value = ((const char*)  tolua_tostring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'queryProperty'",NULL);
#endif
 {
  GameObjectList* tolua_ret = (GameObjectList*)  self->queryProperty(property,value);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"GameObjectList");
 }
 }
 return 1;
tolua_lerror:
 return tolua_Aztec_Lua_Bind_GameStateController_queryProperty00(tolua_S);
}

/* method: getActiveCamera of class  GameStateController */
static int tolua_Aztec_Lua_Bind_GameStateController_getActiveCamera00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"GameStateController",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GameStateController* self = (GameStateController*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getActiveCamera'",NULL);
#endif
 {
  Camera* tolua_ret = (Camera*)  self->getActiveCamera();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Camera");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getActiveCamera'.",&tolua_err);
 return 0;
#endif
}

/* method: addOverlay of class  GameStateController */
static int tolua_Aztec_Lua_Bind_GameStateController_addOverlay00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"GameStateController",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"GameObject",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GameStateController* self = (GameStateController*)  tolua_tousertype(tolua_S,1,0);
  GameObject* object = ((GameObject*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addOverlay'",NULL);
#endif
 {
  GameObject* tolua_ret = (GameObject*)  self->addOverlay(object);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"GameObject");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addOverlay'.",&tolua_err);
 return 0;
#endif
}

/* method: removeOverlay of class  GameStateController */
static int tolua_Aztec_Lua_Bind_GameStateController_removeOverlay00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"GameStateController",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"GameObject",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GameStateController* self = (GameStateController*)  tolua_tousertype(tolua_S,1,0);
  GameObject* object = ((GameObject*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeOverlay'",NULL);
#endif
 {
  GameObject* tolua_ret = (GameObject*)  self->removeOverlay(object);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"GameObject");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeOverlay'.",&tolua_err);
 return 0;
#endif
}

/* method: addBackDrops of class  GameStateController */
static int tolua_Aztec_Lua_Bind_GameStateController_addBackDrops00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"GameStateController",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"GameObject",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GameStateController* self = (GameStateController*)  tolua_tousertype(tolua_S,1,0);
  GameObject* object = ((GameObject*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addBackDrops'",NULL);
#endif
 {
  GameObject* tolua_ret = (GameObject*)  self->addBackDrops(object);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"GameObject");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addBackDrops'.",&tolua_err);
 return 0;
#endif
}

/* method: removeBackDrops of class  GameStateController */
static int tolua_Aztec_Lua_Bind_GameStateController_removeBackDrops00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"GameStateController",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"GameObject",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GameStateController* self = (GameStateController*)  tolua_tousertype(tolua_S,1,0);
  GameObject* object = ((GameObject*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeBackDrops'",NULL);
#endif
 {
  GameObject* tolua_ret = (GameObject*)  self->removeBackDrops(object);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"GameObject");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeBackDrops'.",&tolua_err);
 return 0;
#endif
}

/* method: addTile of class  GameStateController */
static int tolua_Aztec_Lua_Bind_GameStateController_addTile00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"GameStateController",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"GameObject",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GameStateController* self = (GameStateController*)  tolua_tousertype(tolua_S,1,0);
  GameObject* object = ((GameObject*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addTile'",NULL);
#endif
 {
  GameObject* tolua_ret = (GameObject*)  self->addTile(object);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"GameObject");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addTile'.",&tolua_err);
 return 0;
#endif
}

/* method: removeTile of class  GameStateController */
static int tolua_Aztec_Lua_Bind_GameStateController_removeTile00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"GameStateController",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"GameObject",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GameStateController* self = (GameStateController*)  tolua_tousertype(tolua_S,1,0);
  GameObject* object = ((GameObject*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeTile'",NULL);
#endif
 {
  GameObject* tolua_ret = (GameObject*)  self->removeTile(object);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"GameObject");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeTile'.",&tolua_err);
 return 0;
#endif
}

/* method: add of class  GameStateController */
static int tolua_Aztec_Lua_Bind_GameStateController_add00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"GameStateController",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"GameObject",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GameStateController* self = (GameStateController*)  tolua_tousertype(tolua_S,1,0);
  GameObject* object = ((GameObject*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'add'",NULL);
#endif
 {
  GameObject* tolua_ret = (GameObject*)  self->add(object);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"GameObject");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'add'.",&tolua_err);
 return 0;
#endif
}

/* method: add of class  GameStateController */
static int tolua_Aztec_Lua_Bind_GameStateController_add01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"GameStateController",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"GameObject",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  GameStateController* self = (GameStateController*)  tolua_tousertype(tolua_S,1,0);
  GameObject* object = ((GameObject*)  tolua_tousertype(tolua_S,2,0));
  unsigned int layer_id = ((unsigned int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'add'",NULL);
#endif
 {
  GameObject* tolua_ret = (GameObject*)  self->add(object,layer_id);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"GameObject");
 }
 }
 return 1;
tolua_lerror:
 return tolua_Aztec_Lua_Bind_GameStateController_add00(tolua_S);
}

/* method: remove of class  GameStateController */
static int tolua_Aztec_Lua_Bind_GameStateController_remove00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"GameStateController",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"GameObject",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GameStateController* self = (GameStateController*)  tolua_tousertype(tolua_S,1,0);
  GameObject* object = ((GameObject*)  tolua_tousertype(tolua_S,2,0));
  unsigned int layer_id = ((unsigned int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'remove'",NULL);
#endif
 {
  GameObject* tolua_ret = (GameObject*)  self->remove(object,layer_id);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"GameObject");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'remove'.",&tolua_err);
 return 0;
#endif
}

/* method: getLayer of class  GameStateController */
static int tolua_Aztec_Lua_Bind_GameStateController_getLayer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"GameStateController",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GameStateController* self = (GameStateController*)  tolua_tousertype(tolua_S,1,0);
  unsigned int layer_id = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getLayer'",NULL);
#endif
 {
  GameObject* tolua_ret = (GameObject*)  self->getLayer(layer_id);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"GameObject");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getLayer'.",&tolua_err);
 return 0;
#endif
}

/* method: setProperty of class  GameStateController */
static int tolua_Aztec_Lua_Bind_GameStateController_setProperty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"GameStateController",0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isstring(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GameStateController* self = (GameStateController*)  tolua_tousertype(tolua_S,1,0);
  const char* property = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* value = ((const char*)  tolua_tostring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setProperty'",NULL);
#endif
 {
  const char* tolua_ret = (const char*)  self->setProperty(property,value);
 tolua_pushstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setProperty'.",&tolua_err);
 return 0;
#endif
}

/* method: getProperty of class  GameStateController */
static int tolua_Aztec_Lua_Bind_GameStateController_getProperty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"GameStateController",0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GameStateController* self = (GameStateController*)  tolua_tousertype(tolua_S,1,0);
  const char* property = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getProperty'",NULL);
#endif
 {
  const char* tolua_ret = (const char*)  self->getProperty(property);
 tolua_pushstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getProperty'.",&tolua_err);
 return 0;
#endif
}

/* method: removeProperty of class  GameStateController */
static int tolua_Aztec_Lua_Bind_GameStateController_removeProperty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"GameStateController",0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GameStateController* self = (GameStateController*)  tolua_tousertype(tolua_S,1,0);
  const char* property = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeProperty'",NULL);
#endif
 {
  self->removeProperty(property);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeProperty'.",&tolua_err);
 return 0;
#endif
}

/* method: clearProperties of class  GameStateController */
static int tolua_Aztec_Lua_Bind_GameStateController_clearProperties00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"GameStateController",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GameStateController* self = (GameStateController*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'clearProperties'",NULL);
#endif
 {
  self->clearProperties();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'clearProperties'.",&tolua_err);
 return 0;
#endif
}

/* method: propertyAt of class  GameStateController */
static int tolua_Aztec_Lua_Bind_GameStateController_propertyAt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"GameStateController",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GameStateController* self = (GameStateController*)  tolua_tousertype(tolua_S,1,0);
  unsigned int index = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'propertyAt'",NULL);
#endif
 {
  const char* tolua_ret = (const char*)  self->propertyAt(index);
 tolua_pushstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'propertyAt'.",&tolua_err);
 return 0;
#endif
}

/* method: getPropertyName of class  GameStateController */
static int tolua_Aztec_Lua_Bind_GameStateController_getPropertyName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"GameStateController",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GameStateController* self = (GameStateController*)  tolua_tousertype(tolua_S,1,0);
  unsigned int index = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPropertyName'",NULL);
#endif
 {
  const char* tolua_ret = (const char*)  self->getPropertyName(index);
 tolua_pushstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPropertyName'.",&tolua_err);
 return 0;
#endif
}

/* method: hasProperty of class  GameStateController */
static int tolua_Aztec_Lua_Bind_GameStateController_hasProperty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"GameStateController",0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GameStateController* self = (GameStateController*)  tolua_tousertype(tolua_S,1,0);
  const char* property = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'hasProperty'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->hasProperty(property);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'hasProperty'.",&tolua_err);
 return 0;
#endif
}

/* method: getPropertyCount of class  GameStateController */
static int tolua_Aztec_Lua_Bind_GameStateController_getPropertyCount00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"GameStateController",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GameStateController* self = (GameStateController*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPropertyCount'",NULL);
#endif
 {
  unsigned int tolua_ret = (unsigned int)  self->getPropertyCount();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPropertyCount'.",&tolua_err);
 return 0;
#endif
}

/* method: clear of class  GameObjectList */
static int tolua_Aztec_Lua_Bind_GameObjectList_clear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"GameObjectList",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GameObjectList* self = (GameObjectList*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'clear'",NULL);
#endif
 {
  self->clear();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'clear'.",&tolua_err);
 return 0;
#endif
}

/* method: add of class  GameObjectList */
static int tolua_Aztec_Lua_Bind_GameObjectList_add00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"GameObjectList",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"GameObject",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GameObjectList* self = (GameObjectList*)  tolua_tousertype(tolua_S,1,0);
  GameObject* object = ((GameObject*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'add'",NULL);
#endif
 {
  GameObject* tolua_ret = (GameObject*)  self->add(object);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"GameObject");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'add'.",&tolua_err);
 return 0;
#endif
}

/* method: get of class  GameObjectList */
static int tolua_Aztec_Lua_Bind_GameObjectList_get00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"GameObjectList",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GameObjectList* self = (GameObjectList*)  tolua_tousertype(tolua_S,1,0);
  unsigned int index = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'get'",NULL);
#endif
 {
  GameObject* tolua_ret = (GameObject*)  self->get(index);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"GameObject");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'get'.",&tolua_err);
 return 0;
#endif
}

/* method: at of class  GameObjectList */
static int tolua_Aztec_Lua_Bind_GameObjectList_at00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"GameObjectList",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GameObjectList* self = (GameObjectList*)  tolua_tousertype(tolua_S,1,0);
  unsigned int index = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'at'",NULL);
#endif
 {
  GameObject* tolua_ret = (GameObject*)  self->at(index);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"GameObject");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'at'.",&tolua_err);
 return 0;
#endif
}

/* method: getSize of class  GameObjectList */
static int tolua_Aztec_Lua_Bind_GameObjectList_getSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"GameObjectList",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GameObjectList* self = (GameObjectList*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getSize'",NULL);
#endif
 {
  unsigned int tolua_ret = (unsigned int)  self->getSize();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getSize'.",&tolua_err);
 return 0;
#endif
}

/* method: remove of class  GameObjectList */
static int tolua_Aztec_Lua_Bind_GameObjectList_remove00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"GameObjectList",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"GameObject",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GameObjectList* self = (GameObjectList*)  tolua_tousertype(tolua_S,1,0);
  GameObject* object = ((GameObject*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'remove'",NULL);
#endif
 {
  self->remove(object);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'remove'.",&tolua_err);
 return 0;
#endif
}

/* method: has of class  GameObjectList */
static int tolua_Aztec_Lua_Bind_GameObjectList_has00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"GameObjectList",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"GameObject",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GameObjectList* self = (GameObjectList*)  tolua_tousertype(tolua_S,1,0);
  GameObject* object = ((GameObject*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'has'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->has(object);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'has'.",&tolua_err);
 return 0;
#endif
}

/* method: setPosition of class  GameObjectList */
static int tolua_Aztec_Lua_Bind_GameObjectList_setPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"GameObjectList",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GameObjectList* self = (GameObjectList*)  tolua_tousertype(tolua_S,1,0);
  unsigned int pos = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPosition'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->setPosition(pos);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setPosition'.",&tolua_err);
 return 0;
#endif
}

/* method: hasNext of class  GameObjectList */
static int tolua_Aztec_Lua_Bind_GameObjectList_hasNext00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"GameObjectList",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GameObjectList* self = (GameObjectList*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'hasNext'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->hasNext();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'hasNext'.",&tolua_err);
 return 0;
#endif
}

/* method: next of class  GameObjectList */
static int tolua_Aztec_Lua_Bind_GameObjectList_next00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"GameObjectList",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GameObjectList* self = (GameObjectList*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'next'",NULL);
#endif
 {
  GameObject* tolua_ret = (GameObject*)  self->next();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"GameObject");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'next'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  GameObjectList */
static int tolua_Aztec_Lua_Bind_GameObjectList_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"GameObjectList",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  GameObjectList* tolua_ret = (GameObjectList*)  new GameObjectList();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"GameObjectList");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  GameObjectList */
static int tolua_Aztec_Lua_Bind_GameObjectList_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"GameObjectList",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GameObjectList* self = (GameObjectList*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
 tolua_release(tolua_S,self);
 delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* get function: TITLE of class  Config */
static int tolua_get_Config_Config_TITLE(lua_State* tolua_S)
{
 tolua_pushstring(tolua_S,(const char*)Config::TITLE);
 return 1;
}

/* set function: TITLE of class  Config */
static int tolua_set_Config_Config_TITLE(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!tolua_isstring(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
 strncpy(Config::TITLE,tolua_tostring(tolua_S,2,0),255-1);
 return 0;
}

/* get function: SCREEN_WIDTH of class  Config */
static int tolua_get_Config_Config_SCREEN_WIDTH(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Config::SCREEN_WIDTH);
 return 1;
}

/* set function: SCREEN_WIDTH of class  Config */
static int tolua_set_Config_Config_SCREEN_WIDTH(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  Config::SCREEN_WIDTH = ((int)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* get function: SCREEN_HEIGHT of class  Config */
static int tolua_get_Config_Config_SCREEN_HEIGHT(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Config::SCREEN_HEIGHT);
 return 1;
}

/* set function: SCREEN_HEIGHT of class  Config */
static int tolua_set_Config_Config_SCREEN_HEIGHT(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  Config::SCREEN_HEIGHT = ((int)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* get function: FULLSCREEN of class  Config */
static int tolua_get_Config_Config_FULLSCREEN(lua_State* tolua_S)
{
 tolua_pushboolean(tolua_S,(bool)Config::FULLSCREEN);
 return 1;
}

/* set function: FULLSCREEN of class  Config */
static int tolua_set_Config_Config_FULLSCREEN(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  Config::FULLSCREEN = ((bool)  tolua_toboolean(tolua_S,2,0));
 return 0;
}

/* get function: DEBUG_DRAW of class  Config */
static int tolua_get_Config_Config_DEBUG_DRAW(lua_State* tolua_S)
{
 tolua_pushboolean(tolua_S,(bool)Config::DEBUG_DRAW);
 return 1;
}

/* set function: DEBUG_DRAW of class  Config */
static int tolua_set_Config_Config_DEBUG_DRAW(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  Config::DEBUG_DRAW = ((bool)  tolua_toboolean(tolua_S,2,0));
 return 0;
}

/* get function: SOUND_CHANNELS of class  Config */
static int tolua_get_Config_Config_SOUND_CHANNELS(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Config::SOUND_CHANNELS);
 return 1;
}

/* set function: SOUND_CHANNELS of class  Config */
static int tolua_set_Config_Config_SOUND_CHANNELS(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  Config::SOUND_CHANNELS = ((int)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* get function: SOUND_FREQUENCY of class  Config */
static int tolua_get_Config_Config_SOUND_FREQUENCY(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Config::SOUND_FREQUENCY);
 return 1;
}

/* set function: SOUND_FREQUENCY of class  Config */
static int tolua_set_Config_Config_SOUND_FREQUENCY(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  Config::SOUND_FREQUENCY = ((int)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* get function: SOUND_BUFFER_SIZE of class  Config */
static int tolua_get_Config_Config_SOUND_BUFFER_SIZE(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Config::SOUND_BUFFER_SIZE);
 return 1;
}

/* set function: SOUND_BUFFER_SIZE of class  Config */
static int tolua_set_Config_Config_SOUND_BUFFER_SIZE(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  Config::SOUND_BUFFER_SIZE = ((int)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* get function: PHYSICS_PIXELS_METERS_RATIO of class  Config */
static int tolua_get_Config_Config_PHYSICS_PIXELS_METERS_RATIO(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Config::PHYSICS_PIXELS_METERS_RATIO);
 return 1;
}

/* set function: PHYSICS_PIXELS_METERS_RATIO of class  Config */
static int tolua_set_Config_Config_PHYSICS_PIXELS_METERS_RATIO(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  Config::PHYSICS_PIXELS_METERS_RATIO = ((float)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* method: new of class  Camera */
static int tolua_Aztec_Lua_Bind_Camera_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Camera",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Camera* tolua_ret = (Camera*)  new Camera();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Camera");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: activate of class  Camera */
static int tolua_Aztec_Lua_Bind_Camera_activate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Camera",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Camera* self = (Camera*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'activate'",NULL);
#endif
 {
  self->activate();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'activate'.",&tolua_err);
 return 0;
#endif
}

/* method: deactivate of class  Camera */
static int tolua_Aztec_Lua_Bind_Camera_deactivate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Camera",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Camera* self = (Camera*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'deactivate'",NULL);
#endif
 {
  self->deactivate();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'deactivate'.",&tolua_err);
 return 0;
#endif
}

/* method: centerOnScreen of class  Camera */
static int tolua_Aztec_Lua_Bind_Camera_centerOnScreen00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Camera",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Camera* self = (Camera*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'centerOnScreen'",NULL);
#endif
 {
  self->centerOnScreen();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'centerOnScreen'.",&tolua_err);
 return 0;
#endif
}

/* method: setColorBalance of class  Camera */
static int tolua_Aztec_Lua_Bind_Camera_setColorBalance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Camera",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,5,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Camera* self = (Camera*)  tolua_tousertype(tolua_S,1,0);
  float r = ((float)  tolua_tonumber(tolua_S,2,0));
  float g = ((float)  tolua_tonumber(tolua_S,3,0));
  float b = ((float)  tolua_tonumber(tolua_S,4,0));
  float a = ((float)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setColorBalance'",NULL);
#endif
 {
  self->setColorBalance(r,g,b,a);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setColorBalance'.",&tolua_err);
 return 0;
#endif
}

/* method: SetOffScreenRenderer of class  GameEngine */
static int tolua_Aztec_Lua_Bind_GameEngine_SetOffscreenRenderer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"GameEngine",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"WebBrowser",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GameEngine* self = (GameEngine*)  tolua_tousertype(tolua_S,1,0);
  WebBrowser* browser = ((WebBrowser*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetOffscreenRenderer'",NULL);
#endif
 {
  self->SetOffscreenRenderer(browser);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetOffscreenRenderer'.",&tolua_err);
 return 0;
#endif
}

/* get function: Arguments of class  GameEngine */
static int tolua_get_GameEngine_GameEngine_Arguments_ptr(lua_State* tolua_S)
{
  GameEngine* self = (GameEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Arguments'",NULL);
#endif
 tolua_pushusertype(tolua_S,(void*)self->Arguments,"PropertyList");
 return 1;
}

/* set function: Arguments of class  GameEngine */
static int tolua_set_GameEngine_GameEngine_Arguments_ptr(lua_State* tolua_S)
{
  GameEngine* self = (GameEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Arguments'",NULL);
 if (!tolua_isusertype(tolua_S,2,"PropertyList",0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Arguments = ((PropertyList*)  tolua_tousertype(tolua_S,2,0));
 return 0;
}

/* method: getInstance of class  GameEngine */
static int tolua_Aztec_Lua_Bind_GameEngine_getInstance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"GameEngine",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  GameEngine* tolua_ret = (GameEngine*)  GameEngine::getInstance();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"GameEngine");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getInstance'.",&tolua_err);
 return 0;
#endif
}

/* method: freeInstance of class  GameEngine */
static int tolua_Aztec_Lua_Bind_GameEngine_freeInstance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"GameEngine",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  GameEngine::freeInstance();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'freeInstance'.",&tolua_err);
 return 0;
#endif
}

/* method: requestShutdown of class  GameEngine */
static int tolua_Aztec_Lua_Bind_GameEngine_requestShutdown00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"GameEngine",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GameEngine* self = (GameEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'requestShutdown'",NULL);
#endif
 {
  self->requestShutdown();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'requestShutdown'.",&tolua_err);
 return 0;
#endif
}

/* method: getCurrentGameState of class  GameEngine */
static int tolua_Aztec_Lua_Bind_GameEngine_getCurrentGameState00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"GameEngine",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GameEngine* self = (GameEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getCurrentGameState'",NULL);
#endif
 {
  GameStateController* tolua_ret = (GameStateController*)  self->getCurrentGameState();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"GameStateController");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getCurrentGameState'.",&tolua_err);
 return 0;
#endif
}

/* method: run of class  GameEngine */
static int tolua_Aztec_Lua_Bind_GameEngine_run00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"GameEngine",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"GameStateController",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GameEngine* self = (GameEngine*)  tolua_tousertype(tolua_S,1,0);
  GameStateController* gs = ((GameStateController*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'run'",NULL);
#endif
 {
  self->run(gs);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'run'.",&tolua_err);
 return 0;
#endif
}

/* method: run of class  GameEngine */
static int tolua_Aztec_Lua_Bind_GameEngine_run01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"GameEngine",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  GameEngine* self = (GameEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'run'",NULL);
#endif
 {
  self->run();
 }
 }
 return 0;
tolua_lerror:
 return tolua_Aztec_Lua_Bind_GameEngine_run00(tolua_S);
}

/* method: getKeyboard of class  GameEngine */
static int tolua_Aztec_Lua_Bind_GameEngine_getKeyboard00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"GameEngine",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GameEngine* self = (GameEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getKeyboard'",NULL);
#endif
 {
  Keyboard* tolua_ret = (Keyboard*)  self->getKeyboard();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Keyboard");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getKeyboard'.",&tolua_err);
 return 0;
#endif
}

/* method: getMouse of class  GameEngine */
static int tolua_Aztec_Lua_Bind_GameEngine_getMouse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"GameEngine",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GameEngine* self = (GameEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getMouse'",NULL);
#endif
 {
  Mouse* tolua_ret = (Mouse*)  self->getMouse();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Mouse");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getMouse'.",&tolua_err);
 return 0;
#endif
}

/* method: getElapsedTime of class  GameEngine */
static int tolua_Aztec_Lua_Bind_GameEngine_getElapsedTime00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"GameEngine",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GameEngine* self = (GameEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getElapsedTime'",NULL);
#endif
 {
  double tolua_ret = (double)  self->getElapsedTime();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getElapsedTime'.",&tolua_err);
 return 0;
#endif
}

/* method: getTrueElapsedTime of class  GameEngine */
static int tolua_Aztec_Lua_Bind_GameEngine_getTrueElapsedTime00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"GameEngine",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GameEngine* self = (GameEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTrueElapsedTime'",NULL);
#endif
 {
  double tolua_ret = (double)  self->getTrueElapsedTime();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getTrueElapsedTime'.",&tolua_err);
 return 0;
#endif
}

/* method: getCurrentTime of class  GameEngine */
static int tolua_Aztec_Lua_Bind_GameEngine_getCurrentTime00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"GameEngine",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GameEngine* self = (GameEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getCurrentTime'",NULL);
#endif
 {
  double tolua_ret = (double)  self->getCurrentTime();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getCurrentTime'.",&tolua_err);
 return 0;
#endif
}

/* method: getTrueCurrentTime of class  GameEngine */
static int tolua_Aztec_Lua_Bind_GameEngine_getTrueCurrentTime00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"GameEngine",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GameEngine* self = (GameEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTrueCurrentTime'",NULL);
#endif
 {
  double tolua_ret = (double)  self->getTrueCurrentTime();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getTrueCurrentTime'.",&tolua_err);
 return 0;
#endif
}

/* get function: NONE of class  EventTypes */
static int tolua_get_EventTypes_EventTypes_NONE(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)EventTypes::NONE);
 return 1;
}

/* get function: OnUpdate of class  EventTypes */
static int tolua_get_EventTypes_EventTypes_OnUpdate(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)EventTypes::OnUpdate);
 return 1;
}

/* get function: OnClick of class  EventTypes */
static int tolua_get_EventTypes_EventTypes_OnClick(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)EventTypes::OnClick);
 return 1;
}

/* get function: OnMouseMove of class  EventTypes */
static int tolua_get_EventTypes_EventTypes_OnMouseMove(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)EventTypes::OnMouseMove);
 return 1;
}

/* get function: OnMouseDown of class  EventTypes */
static int tolua_get_EventTypes_EventTypes_OnMouseDown(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)EventTypes::OnMouseDown);
 return 1;
}

/* get function: OnMouseUp of class  EventTypes */
static int tolua_get_EventTypes_EventTypes_OnMouseUp(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)EventTypes::OnMouseUp);
 return 1;
}

/* get function: OnKeyDown of class  EventTypes */
static int tolua_get_EventTypes_EventTypes_OnKeyDown(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)EventTypes::OnKeyDown);
 return 1;
}

/* get function: OnKeyUp of class  EventTypes */
static int tolua_get_EventTypes_EventTypes_OnKeyUp(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)EventTypes::OnKeyUp);
 return 1;
}

/* get function: OnBeginContact of class  EventTypes */
static int tolua_get_EventTypes_EventTypes_OnBeginContact(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)EventTypes::OnBeginContact);
 return 1;
}

/* get function: OnEndContact of class  EventTypes */
static int tolua_get_EventTypes_EventTypes_OnEndContact(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)EventTypes::OnEndContact);
 return 1;
}

/* get function: OnMusicStarted of class  EventTypes */
static int tolua_get_EventTypes_EventTypes_OnMusicStarted(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)EventTypes::OnMusicStarted);
 return 1;
}

/* get function: OnMusicFinished of class  EventTypes */
static int tolua_get_EventTypes_EventTypes_OnMusicFinished(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)EventTypes::OnMusicFinished);
 return 1;
}

/* get function: OnAnimationStarted of class  EventTypes */
static int tolua_get_EventTypes_EventTypes_OnAnimationStarted(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)EventTypes::OnAnimationStarted);
 return 1;
}

/* get function: OnAnimationFinished of class  EventTypes */
static int tolua_get_EventTypes_EventTypes_OnAnimationFinished(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)EventTypes::OnAnimationFinished);
 return 1;
}

/* get function: OnBeforeDraw of class  EventTypes */
static int tolua_get_EventTypes_EventTypes_OnBeforeDraw(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)EventTypes::OnBeforeDraw);
 return 1;
}

/* get function: OnAfterDraw of class  EventTypes */
static int tolua_get_EventTypes_EventTypes_OnAfterDraw(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)EventTypes::OnAfterDraw);
 return 1;
}

/* get function: ALL of class  EventTypes */
static int tolua_get_EventTypes_EventTypes_ALL(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)EventTypes::ALL);
 return 1;
}

/* method: XOR of class  Bitwise */
static int tolua_Aztec_Lua_Bind_Bitwise_XOR00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Bitwise",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  long a = ((long)  tolua_tonumber(tolua_S,2,0));
  long b = ((long)  tolua_tonumber(tolua_S,3,0));
 {
  long tolua_ret = (long)  Bitwise::XOR(a,b);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'XOR'.",&tolua_err);
 return 0;
#endif
}

/* method: AND of class  Bitwise */
static int tolua_Aztec_Lua_Bind_Bitwise_AND00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Bitwise",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  long a = ((long)  tolua_tonumber(tolua_S,2,0));
  long b = ((long)  tolua_tonumber(tolua_S,3,0));
 {
  long tolua_ret = (long)  Bitwise::AND(a,b);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AND'.",&tolua_err);
 return 0;
#endif
}

/* method: OR of class  Bitwise */
static int tolua_Aztec_Lua_Bind_Bitwise_OR00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Bitwise",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  long a = ((long)  tolua_tonumber(tolua_S,2,0));
  long b = ((long)  tolua_tonumber(tolua_S,3,0));
 {
  long tolua_ret = (long)  Bitwise::OR(a,b);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'OR'.",&tolua_err);
 return 0;
#endif
}

/* method: NOT of class  Bitwise */
static int tolua_Aztec_Lua_Bind_Bitwise_NOT00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Bitwise",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  long a = ((long)  tolua_tonumber(tolua_S,2,0));
 {
  long tolua_ret = (long)  Bitwise::NOT(a);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'NOT'.",&tolua_err);
 return 0;
#endif
}

/* get function: DIFFUSE of class  Texture */
static int tolua_get_Texture_Texture_unsigned_DIFFUSE(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Texture::DIFFUSE);
 return 1;
}

/* get function: NORMAL of class  Texture */
static int tolua_get_Texture_Texture_unsigned_NORMAL(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Texture::NORMAL);
 return 1;
}

/* get function: TEXTURE0 of class  Texture */
static int tolua_get_Texture_Texture_unsigned_TEXTURE0(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Texture::TEXTURE0);
 return 1;
}

/* get function: TEXTURE1 of class  Texture */
static int tolua_get_Texture_Texture_unsigned_TEXTURE1(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Texture::TEXTURE1);
 return 1;
}

/* get function: TEXTURE2 of class  Texture */
static int tolua_get_Texture_Texture_unsigned_TEXTURE2(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Texture::TEXTURE2);
 return 1;
}

/* get function: TEXTURE3 of class  Texture */
static int tolua_get_Texture_Texture_unsigned_TEXTURE3(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Texture::TEXTURE3);
 return 1;
}

/* get function: TEXTURE4 of class  Texture */
static int tolua_get_Texture_Texture_unsigned_TEXTURE4(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Texture::TEXTURE4);
 return 1;
}

/* get function: TEXTURE5 of class  Texture */
static int tolua_get_Texture_Texture_unsigned_TEXTURE5(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Texture::TEXTURE5);
 return 1;
}

/* get function: TEXTURE6 of class  Texture */
static int tolua_get_Texture_Texture_unsigned_TEXTURE6(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Texture::TEXTURE6);
 return 1;
}

/* get function: TEXTURE7 of class  Texture */
static int tolua_get_Texture_Texture_unsigned_TEXTURE7(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Texture::TEXTURE7);
 return 1;
}

/* get function: TEXTURE8 of class  Texture */
static int tolua_get_Texture_Texture_unsigned_TEXTURE8(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Texture::TEXTURE8);
 return 1;
}

/* method: new of class  Texture */
static int tolua_Aztec_Lua_Bind_Texture_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Texture",0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const char* path = ((const char*)  tolua_tostring(tolua_S,2,0));
  int width = ((int)  tolua_tonumber(tolua_S,3,0));
  int height = ((int)  tolua_tonumber(tolua_S,4,0));
 {
  Texture* tolua_ret = (Texture*)  new Texture(path,width,height);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Texture");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: getWidth of class  Texture */
static int tolua_Aztec_Lua_Bind_Texture_getWidth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Texture",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Texture* self = (Texture*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getWidth'",NULL);
#endif
 {
  const int tolua_ret = (const int)  self->getWidth();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getWidth'.",&tolua_err);
 return 0;
#endif
}

/* method: getHeight of class  Texture */
static int tolua_Aztec_Lua_Bind_Texture_getHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Texture",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Texture* self = (Texture*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getHeight'",NULL);
#endif
 {
  const int tolua_ret = (const int)  self->getHeight();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getHeight'.",&tolua_err);
 return 0;
#endif
}

/* method: getOriginalWidth of class  Texture */
static int tolua_Aztec_Lua_Bind_Texture_getOriginalWidth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Texture",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Texture* self = (Texture*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getOriginalWidth'",NULL);
#endif
 {
  const int tolua_ret = (const int)  self->getOriginalWidth();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getOriginalWidth'.",&tolua_err);
 return 0;
#endif
}

/* method: getOriginalHeight of class  Texture */
static int tolua_Aztec_Lua_Bind_Texture_getOriginalHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Texture",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Texture* self = (Texture*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getOriginalHeight'",NULL);
#endif
 {
  const int tolua_ret = (const int)  self->getOriginalHeight();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getOriginalHeight'.",&tolua_err);
 return 0;
#endif
}

/* method: getPath of class  Texture */
static int tolua_Aztec_Lua_Bind_Texture_getPath00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Texture",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Texture* self = (Texture*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPath'",NULL);
#endif
 {
  const char* tolua_ret = (const char*)  self->getPath();
 tolua_pushstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPath'.",&tolua_err);
 return 0;
#endif
}

/* method: getTextureID of class  Texture */
static int tolua_Aztec_Lua_Bind_Texture_getTextureID00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Texture",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Texture* self = (Texture*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTextureID'",NULL);
#endif
 {
  unsigned const int tolua_ret = (unsigned const int)  self->getTextureID();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getTextureID'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  Texture */
static int tolua_Aztec_Lua_Bind_Texture_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Texture",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Texture* self = (Texture*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
 tolua_release(tolua_S,self);
 delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* get function: DRAW_QUADS of class  Shape */
static int tolua_get_Shape_Shape_DRAW_QUADS(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Shape::DRAW_QUADS);
 return 1;
}

/* get function: DRAW_TRIANGLES of class  Shape */
static int tolua_get_Shape_Shape_DRAW_TRIANGLES(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Shape::DRAW_TRIANGLES);
 return 1;
}

/* get function: DRAW_TRIANGLE_FAN of class  Shape */
static int tolua_get_Shape_Shape_DRAW_TRIANGLE_FAN(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Shape::DRAW_TRIANGLE_FAN);
 return 1;
}

/* get function: DRAW_LINES of class  Shape */
static int tolua_get_Shape_Shape_DRAW_LINES(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Shape::DRAW_LINES);
 return 1;
}

/* get function: DRAW_POINTS of class  Shape */
static int tolua_get_Shape_Shape_DRAW_POINTS(lua_State* tolua_S)
{
 tolua_pushnumber(tolua_S,(lua_Number)Shape::DRAW_POINTS);
 return 1;
}

/* method: setDrawMode of class  Shape */
static int tolua_Aztec_Lua_Bind_Shape_setDrawMode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Shape",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Shape* self = (Shape*)  tolua_tousertype(tolua_S,1,0);
  unsigned int mode = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
  unsigned int first = ((unsigned int)  tolua_tonumber(tolua_S,3,0));
  unsigned int count = ((unsigned int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setDrawMode'",NULL);
#endif
 {
  self->setDrawMode(mode,first,count);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setDrawMode'.",&tolua_err);
 return 0;
#endif
}

/* method: setFillMode of class  Shape */
static int tolua_Aztec_Lua_Bind_Shape_setFillMode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Shape",0,&tolua_err) || 
 !tolua_isboolean(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Shape* self = (Shape*)  tolua_tousertype(tolua_S,1,0);
  bool active = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setFillMode'",NULL);
#endif
 {
  self->setFillMode(active);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setFillMode'.",&tolua_err);
 return 0;
#endif
}

/* method: setColorBalance of class  Shape */
static int tolua_Aztec_Lua_Bind_Shape_setColorBalance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Shape",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,5,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Shape* self = (Shape*)  tolua_tousertype(tolua_S,1,0);
  float r = ((float)  tolua_tonumber(tolua_S,2,0));
  float g = ((float)  tolua_tonumber(tolua_S,3,0));
  float b = ((float)  tolua_tonumber(tolua_S,4,0));
  float a = ((float)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setColorBalance'",NULL);
#endif
 {
  self->setColorBalance(r,g,b,a);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setColorBalance'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  Shape */
static int tolua_Aztec_Lua_Bind_Shape_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Shape",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"Shader",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Shader* shader = ((Shader*)  tolua_tousertype(tolua_S,2,0));
 {
  Shape* tolua_ret = (Shape*)  new Shape(shader);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Shape");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  Shape */
static int tolua_Aztec_Lua_Bind_Shape_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Shape",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
 {
  Shape* tolua_ret = (Shape*)  new Shape();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Shape");
 }
 }
 return 1;
tolua_lerror:
 return tolua_Aztec_Lua_Bind_Shape_new00(tolua_S);
}

/* method: setShader of class  Shape */
static int tolua_Aztec_Lua_Bind_Shape_setShader00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Shape",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"Shader",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Shape* self = (Shape*)  tolua_tousertype(tolua_S,1,0);
  Shader* shader = ((Shader*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setShader'",NULL);
#endif
 {
  Shader* tolua_ret = (Shader*)  self->setShader(shader);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Shader");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setShader'.",&tolua_err);
 return 0;
#endif
}

/* method: getShader of class  Shape */
static int tolua_Aztec_Lua_Bind_Shape_getShader00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Shape",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Shape* self = (Shape*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getShader'",NULL);
#endif
 {
  Shader* tolua_ret = (Shader*)  self->getShader();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Shader");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getShader'.",&tolua_err);
 return 0;
#endif
}

/* method: getVAO of class  Shape */
static int tolua_Aztec_Lua_Bind_Shape_getVAO00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Shape",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Shape* self = (Shape*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getVAO'",NULL);
#endif
 {
  VertexArrayObject* tolua_ret = (VertexArrayObject*)  self->getVAO();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"VertexArrayObject");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getVAO'.",&tolua_err);
 return 0;
#endif
}

/* method: setVAO of class  Shape */
static int tolua_Aztec_Lua_Bind_Shape_setVAO00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Shape",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"VertexArrayObject",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Shape* self = (Shape*)  tolua_tousertype(tolua_S,1,0);
  VertexArrayObject* VAO = ((VertexArrayObject*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setVAO'",NULL);
#endif
 {
  VertexArrayObject* tolua_ret = (VertexArrayObject*)  self->setVAO(VAO);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"VertexArrayObject");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setVAO'.",&tolua_err);
 return 0;
#endif
}

/* method: setTranslation of class  Shape */
static int tolua_Aztec_Lua_Bind_Shape_setTranslation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Shape",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Shape* self = (Shape*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float z = ((float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setTranslation'",NULL);
#endif
 {
  self->setTranslation(x,y,z);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setTranslation'.",&tolua_err);
 return 0;
#endif
}

/* method: setPivot of class  Shape */
static int tolua_Aztec_Lua_Bind_Shape_setPivot00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Shape",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Shape* self = (Shape*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float z = ((float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPivot'",NULL);
#endif
 {
  self->setPivot(x,y,z);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setPivot'.",&tolua_err);
 return 0;
#endif
}

/* method: setRotation of class  Shape */
static int tolua_Aztec_Lua_Bind_Shape_setRotation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Shape",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Shape* self = (Shape*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float z = ((float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setRotation'",NULL);
#endif
 {
  self->setRotation(x,y,z);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setRotation'.",&tolua_err);
 return 0;
#endif
}

/* method: setPostRotation of class  Shape */
static int tolua_Aztec_Lua_Bind_Shape_setPostRotation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Shape",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Shape* self = (Shape*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float z = ((float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPostRotation'",NULL);
#endif
 {
  self->setPostRotation(x,y,z);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setPostRotation'.",&tolua_err);
 return 0;
#endif
}

/* method: setScale of class  Shape */
static int tolua_Aztec_Lua_Bind_Shape_setScale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Shape",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Shape* self = (Shape*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float z = ((float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setScale'",NULL);
#endif
 {
  self->setScale(x,y,z);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setScale'.",&tolua_err);
 return 0;
#endif
}

/* method: setScale of class  Shape */
static int tolua_Aztec_Lua_Bind_Shape_setScale01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Shape",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Shape* self = (Shape*)  tolua_tousertype(tolua_S,1,0);
  float s = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setScale'",NULL);
#endif
 {
  self->setScale(s);
 }
 }
 return 0;
tolua_lerror:
 return tolua_Aztec_Lua_Bind_Shape_setScale00(tolua_S);
}

/* method: getTexture of class  Shape */
static int tolua_Aztec_Lua_Bind_Shape_getTexture00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Shape",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Shape* self = (Shape*)  tolua_tousertype(tolua_S,1,0);
  unsigned int idx = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTexture'",NULL);
#endif
 {
  Texture* tolua_ret = (Texture*)  self->getTexture(idx);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Texture");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getTexture'.",&tolua_err);
 return 0;
#endif
}

/* method: setTexture of class  Shape */
static int tolua_Aztec_Lua_Bind_Shape_setTexture00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Shape",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isusertype(tolua_S,3,"Texture",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Shape* self = (Shape*)  tolua_tousertype(tolua_S,1,0);
  unsigned int idx = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
  Texture* texture = ((Texture*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setTexture'",NULL);
#endif
 {
  Texture* tolua_ret = (Texture*)  self->setTexture(idx,texture);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Texture");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setTexture'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  Shape */
static int tolua_Aztec_Lua_Bind_Shape_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Shape",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Shape* self = (Shape*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
 tolua_release(tolua_S,self);
 delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* method: Draw of class  Shape */
static int tolua_Aztec_Lua_Bind_Shape_Draw00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Shape",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Shape* self = (Shape*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Draw'",NULL);
#endif
 {
  self->Draw();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Draw'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  Plane */
static int tolua_Aztec_Lua_Bind_Plane_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Plane",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"Shader",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isusertype(tolua_S,5,"Texture",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Shader* shader = ((Shader*)  tolua_tousertype(tolua_S,2,0));
  int width = ((int)  tolua_tonumber(tolua_S,3,0));
  int height = ((int)  tolua_tonumber(tolua_S,4,0));
  Texture* texture = ((Texture*)  tolua_tousertype(tolua_S,5,0));
 {
  Plane* tolua_ret = (Plane*)  new Plane(shader,width,height,texture);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Plane");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  Plane */
static int tolua_Aztec_Lua_Bind_Plane_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Plane",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"Texture",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Texture* texture = ((Texture*)  tolua_tousertype(tolua_S,2,0));
 {
  Plane* tolua_ret = (Plane*)  new Plane(texture);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Plane");
 }
 }
 return 1;
tolua_lerror:
 return tolua_Aztec_Lua_Bind_Plane_new00(tolua_S);
}

/* method: delete of class  Plane */
static int tolua_Aztec_Lua_Bind_Plane_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Plane",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Plane* self = (Plane*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
 tolua_release(tolua_S,self);
 delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  VertexBufferObject */
static int tolua_Aztec_Lua_Bind_VertexBufferObject_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"VertexBufferObject",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_istable(tolua_S,4,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  unsigned int size = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
  unsigned int count = ((unsigned int)  tolua_tonumber(tolua_S,3,0));
#ifdef __cplusplus
  float* data = new float[count];
#else
  float* data = (float*) malloc((count)*sizeof(float));
#endif
 {
#ifndef TOLUA_RELEASE
 if (!tolua_isnumberarray(tolua_S,4,count,0,&tolua_err))
 goto tolua_lerror;
 else
#endif
 {
 int i;
 for(i=0; i<count;i++)
  data[i] = ((float)  tolua_tofieldnumber(tolua_S,4,i+1,0));
 }
 }
 {
  VertexBufferObject* tolua_ret = (VertexBufferObject*)  new VertexBufferObject(size,count,data);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"VertexBufferObject");
 }
 {
 int i;
 for(i=0; i<count;i++)
 tolua_pushfieldnumber(tolua_S,4,i+1,(lua_Number) data[i]);
 }
#ifdef __cplusplus
 delete [] data;
#else
 free(data);
#endif
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  VertexBufferObject */
static int tolua_Aztec_Lua_Bind_VertexBufferObject_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VertexBufferObject",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VertexBufferObject* self = (VertexBufferObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
 tolua_release(tolua_S,self);
 delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* method: getCount of class  VertexBufferObject */
static int tolua_Aztec_Lua_Bind_VertexBufferObject_getCount00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VertexBufferObject",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VertexBufferObject* self = (VertexBufferObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getCount'",NULL);
#endif
 {
  unsigned int tolua_ret = (unsigned int)  self->getCount();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getCount'.",&tolua_err);
 return 0;
#endif
}

/* method: getVBO of class  VertexBufferObject */
static int tolua_Aztec_Lua_Bind_VertexBufferObject_getVBO00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VertexBufferObject",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VertexBufferObject* self = (VertexBufferObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getVBO'",NULL);
#endif
 {
  unsigned int tolua_ret = (unsigned int)  self->getVBO();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getVBO'.",&tolua_err);
 return 0;
#endif
}

/* method: getBufferSize of class  VertexBufferObject */
static int tolua_Aztec_Lua_Bind_VertexBufferObject_getBufferSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VertexBufferObject",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VertexBufferObject* self = (VertexBufferObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getBufferSize'",NULL);
#endif
 {
  unsigned int tolua_ret = (unsigned int)  self->getBufferSize();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getBufferSize'.",&tolua_err);
 return 0;
#endif
}

/* method: getElementSize of class  VertexBufferObject */
static int tolua_Aztec_Lua_Bind_VertexBufferObject_getElementSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VertexBufferObject",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VertexBufferObject* self = (VertexBufferObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getElementSize'",NULL);
#endif
 {
  unsigned int tolua_ret = (unsigned int)  self->getElementSize();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getElementSize'.",&tolua_err);
 return 0;
#endif
}

/* method: bindBuffer of class  VertexBufferObject */
static int tolua_Aztec_Lua_Bind_VertexBufferObject_bindBuffer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VertexBufferObject",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VertexBufferObject* self = (VertexBufferObject*)  tolua_tousertype(tolua_S,1,0);
  unsigned int usage = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'bindBuffer'",NULL);
#endif
 {
  self->bindBuffer(usage);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'bindBuffer'.",&tolua_err);
 return 0;
#endif
}

/* method: bindBuffer of class  VertexBufferObject */
static int tolua_Aztec_Lua_Bind_VertexBufferObject_bindBuffer01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VertexBufferObject",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  VertexBufferObject* self = (VertexBufferObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'bindBuffer'",NULL);
#endif
 {
  self->bindBuffer();
 }
 }
 return 0;
tolua_lerror:
 return tolua_Aztec_Lua_Bind_VertexBufferObject_bindBuffer00(tolua_S);
}

/* method: updateBuffer of class  VertexBufferObject */
static int tolua_Aztec_Lua_Bind_VertexBufferObject_updateBuffer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VertexBufferObject",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_istable(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VertexBufferObject* self = (VertexBufferObject*)  tolua_tousertype(tolua_S,1,0);
  unsigned int count = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
#ifdef __cplusplus
  float* data = new float[count];
#else
  float* data = (float*) malloc((count)*sizeof(float));
#endif
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'updateBuffer'",NULL);
#endif
 {
#ifndef TOLUA_RELEASE
 if (!tolua_isnumberarray(tolua_S,3,count,0,&tolua_err))
 goto tolua_lerror;
 else
#endif
 {
 int i;
 for(i=0; i<count;i++)
  data[i] = ((float)  tolua_tofieldnumber(tolua_S,3,i+1,0));
 }
 }
 {
  self->updateBuffer(count,data);
 }
 {
 int i;
 for(i=0; i<count;i++)
 tolua_pushfieldnumber(tolua_S,3,i+1,(lua_Number) data[i]);
 }
#ifdef __cplusplus
 delete [] data;
#else
 free(data);
#endif
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'updateBuffer'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  VertexArrayObject */
static int tolua_Aztec_Lua_Bind_VertexArrayObject_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"VertexArrayObject",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  VertexArrayObject* tolua_ret = (VertexArrayObject*)  new VertexArrayObject();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"VertexArrayObject");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  VertexArrayObject */
static int tolua_Aztec_Lua_Bind_VertexArrayObject_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VertexArrayObject",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VertexArrayObject* self = (VertexArrayObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
 tolua_release(tolua_S,self);
 delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* method: addVBO of class  VertexArrayObject */
static int tolua_Aztec_Lua_Bind_VertexArrayObject_addVBO00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VertexArrayObject",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"VertexBufferObject",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VertexArrayObject* self = (VertexArrayObject*)  tolua_tousertype(tolua_S,1,0);
  VertexBufferObject* vbo = ((VertexBufferObject*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addVBO'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->addVBO(vbo);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addVBO'.",&tolua_err);
 return 0;
#endif
}

/* method: getVBO of class  VertexArrayObject */
static int tolua_Aztec_Lua_Bind_VertexArrayObject_getVBO00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VertexArrayObject",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VertexArrayObject* self = (VertexArrayObject*)  tolua_tousertype(tolua_S,1,0);
  int idx = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getVBO'",NULL);
#endif
 {
  VertexBufferObject* tolua_ret = (VertexBufferObject*)  self->getVBO(idx);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"VertexBufferObject");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getVBO'.",&tolua_err);
 return 0;
#endif
}

/* method: generate of class  VertexArrayObject */
static int tolua_Aztec_Lua_Bind_VertexArrayObject_generate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VertexArrayObject",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VertexArrayObject* self = (VertexArrayObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'generate'",NULL);
#endif
 {
  unsigned int tolua_ret = (unsigned int)  self->generate();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'generate'.",&tolua_err);
 return 0;
#endif
}

/* method: getId of class  VertexArrayObject */
static int tolua_Aztec_Lua_Bind_VertexArrayObject_getId00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"VertexArrayObject",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  VertexArrayObject* self = (VertexArrayObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getId'",NULL);
#endif
 {
  unsigned int tolua_ret = (unsigned int)  self->getId();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getId'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  WebBrowser */
static int tolua_Aztec_Lua_Bind_WebBrowser_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"WebBrowser",0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const char* url = ((const char*)  tolua_tostring(tolua_S,2,0));
  int width = ((int)  tolua_tonumber(tolua_S,3,0));
  int height = ((int)  tolua_tonumber(tolua_S,4,0));
 {
  WebBrowser* tolua_ret = (WebBrowser*)  new WebBrowser(url,width,height);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"WebBrowser");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  WebBrowser */
static int tolua_Aztec_Lua_Bind_WebBrowser_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"WebBrowser",0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isboolean(tolua_S,5,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const char* url = ((const char*)  tolua_tostring(tolua_S,2,0));
  int width = ((int)  tolua_tonumber(tolua_S,3,0));
  int height = ((int)  tolua_tonumber(tolua_S,4,0));
  bool transparent = ((bool)  tolua_toboolean(tolua_S,5,0));
 {
  WebBrowser* tolua_ret = (WebBrowser*)  new WebBrowser(url,width,height,transparent);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"WebBrowser");
 }
 }
 return 1;
tolua_lerror:
 return tolua_Aztec_Lua_Bind_WebBrowser_new00(tolua_S);
}

/* method: new of class  WebBrowser */
static int tolua_Aztec_Lua_Bind_WebBrowser_new02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"WebBrowser",0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isboolean(tolua_S,5,0,&tolua_err) || 
 !tolua_isboolean(tolua_S,6,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const char* url = ((const char*)  tolua_tostring(tolua_S,2,0));
  int width = ((int)  tolua_tonumber(tolua_S,3,0));
  int height = ((int)  tolua_tonumber(tolua_S,4,0));
  bool transparent = ((bool)  tolua_toboolean(tolua_S,5,0));
  bool offscreen = ((bool)  tolua_toboolean(tolua_S,6,0));
 {
  WebBrowser* tolua_ret = (WebBrowser*)  new WebBrowser(url,width,height,transparent,offscreen);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"WebBrowser");
 }
 }
 return 1;
tolua_lerror:
 return tolua_Aztec_Lua_Bind_WebBrowser_new01(tolua_S);
}

/* method: Navigate of class  WebBrowser */
static int tolua_Aztec_Lua_Bind_WebBrowser_Navigate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"WebBrowser",0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  WebBrowser* self = (WebBrowser*)  tolua_tousertype(tolua_S,1,0);
  const char* url = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Navigate'",NULL);
#endif
 {
  self->Navigate(url);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Navigate'.",&tolua_err);
 return 0;
#endif
}

/* method: GoBack of class  WebBrowser */
static int tolua_Aztec_Lua_Bind_WebBrowser_GoBack00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"WebBrowser",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  WebBrowser* self = (WebBrowser*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GoBack'",NULL);
#endif
 {
  self->GoBack();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GoBack'.",&tolua_err);
 return 0;
#endif
}

/* method: GoForward of class  WebBrowser */
static int tolua_Aztec_Lua_Bind_WebBrowser_GoForward00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"WebBrowser",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  WebBrowser* self = (WebBrowser*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GoForward'",NULL);
#endif
 {
  self->GoForward();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GoForward'.",&tolua_err);
 return 0;
#endif
}

/* method: Stop of class  WebBrowser */
static int tolua_Aztec_Lua_Bind_WebBrowser_Stop00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"WebBrowser",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  WebBrowser* self = (WebBrowser*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Stop'",NULL);
#endif
 {
  self->Stop();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Stop'.",&tolua_err);
 return 0;
#endif
}

/* method: isLoading of class  WebBrowser */
static int tolua_Aztec_Lua_Bind_WebBrowser_isLoading00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"WebBrowser",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  WebBrowser* self = (WebBrowser*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isLoading'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->isLoading();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isLoading'.",&tolua_err);
 return 0;
#endif
}

/* method: Refresh of class  WebBrowser */
static int tolua_Aztec_Lua_Bind_WebBrowser_Refresh00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"WebBrowser",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  WebBrowser* self = (WebBrowser*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Refresh'",NULL);
#endif
 {
  self->Refresh();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Refresh'.",&tolua_err);
 return 0;
#endif
}

/* method: setAlwaysFocused of class  WebBrowser */
static int tolua_Aztec_Lua_Bind_WebBrowser_setAlwaysFocused00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"WebBrowser",0,&tolua_err) || 
 !tolua_isboolean(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  WebBrowser* self = (WebBrowser*)  tolua_tousertype(tolua_S,1,0);
  bool always_focused = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setAlwaysFocused'",NULL);
#endif
 {
  self->setAlwaysFocused(always_focused);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setAlwaysFocused'.",&tolua_err);
 return 0;
#endif
}

/* method: getAlwaysFocused of class  WebBrowser */
static int tolua_Aztec_Lua_Bind_WebBrowser_getAlwaysFocused00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"WebBrowser",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  WebBrowser* self = (WebBrowser*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAlwaysFocused'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->getAlwaysFocused();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAlwaysFocused'.",&tolua_err);
 return 0;
#endif
}

/* method: setShader of class  WebBrowser */
static int tolua_Aztec_Lua_Bind_WebBrowser_setShader00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"WebBrowser",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"Shader",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  WebBrowser* self = (WebBrowser*)  tolua_tousertype(tolua_S,1,0);
  Shader* shader = ((Shader*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setShader'",NULL);
#endif
 {
  Shader* tolua_ret = (Shader*)  self->setShader(shader);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Shader");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setShader'.",&tolua_err);
 return 0;
#endif
}

/* method: getShader of class  WebBrowser */
static int tolua_Aztec_Lua_Bind_WebBrowser_getShader00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"WebBrowser",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  WebBrowser* self = (WebBrowser*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getShader'",NULL);
#endif
 {
  Shader* tolua_ret = (Shader*)  self->getShader();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Shader");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getShader'.",&tolua_err);
 return 0;
#endif
}

/* method: getPlane of class  WebBrowser */
static int tolua_Aztec_Lua_Bind_WebBrowser_getPlane00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"WebBrowser",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  WebBrowser* self = (WebBrowser*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPlane'",NULL);
#endif
 {
  Plane* tolua_ret = (Plane*)  self->getPlane();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Plane");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPlane'.",&tolua_err);
 return 0;
#endif
}

/* method: ExecuteScript of class  WebBrowser */
static int tolua_Aztec_Lua_Bind_WebBrowser_ExecuteScript00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"WebBrowser",0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  WebBrowser* self = (WebBrowser*)  tolua_tousertype(tolua_S,1,0);
  const char* script = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ExecuteScript'",NULL);
#endif
 {
  self->ExecuteScript(script);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ExecuteScript'.",&tolua_err);
 return 0;
#endif
}

/* method: clear of class  PointList2D */
static int tolua_Aztec_Lua_Bind_PointList2D_clear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"PointList2D",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  PointList2D* self = (PointList2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'clear'",NULL);
#endif
 {
  self->clear();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'clear'.",&tolua_err);
 return 0;
#endif
}

/* method: clear of class  PointList2D */
static int tolua_Aztec_Lua_Bind_PointList2D_clear01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"PointList2D",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  PointList2D* self = (PointList2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'clear'",NULL);
#endif
 {
  self->clear();
 }
 }
 return 0;
tolua_lerror:
 return tolua_Aztec_Lua_Bind_PointList2D_clear00(tolua_S);
}

/* method: add of class  PointList2D */
static int tolua_Aztec_Lua_Bind_PointList2D_add00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"PointList2D",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  PointList2D* self = (PointList2D*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'add'",NULL);
#endif
 {
  Vector2 tolua_ret =  self->add(x,y);
 {
#ifdef __cplusplus
 void* tolua_obj = new Vector2(tolua_ret);
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect_Vector2),"Vector2");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector2));
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,NULL),"Vector2");
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'add'.",&tolua_err);
 return 0;
#endif
}

/* method: add of class  PointList2D */
static int tolua_Aztec_Lua_Bind_PointList2D_add01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"PointList2D",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"Vector2",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  PointList2D* self = (PointList2D*)  tolua_tousertype(tolua_S,1,0);
  Vector2 v = *((Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'add'",NULL);
#endif
 {
  Vector2 tolua_ret =  self->add(v);
 {
#ifdef __cplusplus
 void* tolua_obj = new Vector2(tolua_ret);
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect_Vector2),"Vector2");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector2));
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,NULL),"Vector2");
#endif
 }
 }
 }
 return 1;
tolua_lerror:
 return tolua_Aztec_Lua_Bind_PointList2D_add00(tolua_S);
}

/* method: get of class  PointList2D */
static int tolua_Aztec_Lua_Bind_PointList2D_get00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"PointList2D",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  PointList2D* self = (PointList2D*)  tolua_tousertype(tolua_S,1,0);
  int idx = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'get'",NULL);
#endif
 {
  Vector2 tolua_ret =  self->get(idx);
 {
#ifdef __cplusplus
 void* tolua_obj = new Vector2(tolua_ret);
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect_Vector2),"Vector2");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector2));
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,NULL),"Vector2");
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'get'.",&tolua_err);
 return 0;
#endif
}

/* method: set of class  PointList2D */
static int tolua_Aztec_Lua_Bind_PointList2D_set00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"PointList2D",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  PointList2D* self = (PointList2D*)  tolua_tousertype(tolua_S,1,0);
  int idx = ((int)  tolua_tonumber(tolua_S,2,0));
  float x = ((float)  tolua_tonumber(tolua_S,3,0));
  float y = ((float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set'",NULL);
#endif
 {
  Vector2 tolua_ret =  self->set(idx,x,y);
 {
#ifdef __cplusplus
 void* tolua_obj = new Vector2(tolua_ret);
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect_Vector2),"Vector2");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector2));
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,NULL),"Vector2");
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set'.",&tolua_err);
 return 0;
#endif
}

/* method: set of class  PointList2D */
static int tolua_Aztec_Lua_Bind_PointList2D_set01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"PointList2D",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isusertype(tolua_S,3,"Vector2",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  PointList2D* self = (PointList2D*)  tolua_tousertype(tolua_S,1,0);
  int idx = ((int)  tolua_tonumber(tolua_S,2,0));
  Vector2 v = *((Vector2*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set'",NULL);
#endif
 {
  Vector2 tolua_ret =  self->set(idx,v);
 {
#ifdef __cplusplus
 void* tolua_obj = new Vector2(tolua_ret);
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect_Vector2),"Vector2");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector2));
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,NULL),"Vector2");
#endif
 }
 }
 }
 return 1;
tolua_lerror:
 return tolua_Aztec_Lua_Bind_PointList2D_set00(tolua_S);
}

/* method: remove of class  PointList2D */
static int tolua_Aztec_Lua_Bind_PointList2D_remove00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"PointList2D",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  PointList2D* self = (PointList2D*)  tolua_tousertype(tolua_S,1,0);
  int idx = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'remove'",NULL);
#endif
 {
  Vector2 tolua_ret =  self->remove(idx);
 {
#ifdef __cplusplus
 void* tolua_obj = new Vector2(tolua_ret);
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect_Vector2),"Vector2");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector2));
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,NULL),"Vector2");
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'remove'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  PointList2D */
static int tolua_Aztec_Lua_Bind_PointList2D_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"PointList2D",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  PointList2D* tolua_ret = (PointList2D*)  new PointList2D();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"PointList2D");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  PointList2D */
static int tolua_Aztec_Lua_Bind_PointList2D_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"PointList2D",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  PointList2D* self = (PointList2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
 tolua_release(tolua_S,self);
 delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* Open lib function */
LUALIB_API int luaopen_Aztec_Lua_Bind (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
 tolua_cclass(tolua_S,"LuaBinded","LuaBinded","",NULL);
 tolua_beginmodule(tolua_S,"LuaBinded");
 tolua_variable(tolua_S,"EventFlags",tolua_get_LuaBinded_LuaBinded_EventFlags,tolua_set_LuaBinded_LuaBinded_EventFlags);
 tolua_function(tolua_S,"resetEventFlags",tolua_Aztec_Lua_Bind_LuaBinded_resetEventFlags00);
 tolua_function(tolua_S,"getClassName",tolua_Aztec_Lua_Bind_LuaBinded_getClassName00);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"Vector2","Vector2","",tolua_collect_Vector2);
#else
 tolua_cclass(tolua_S,"Vector2","Vector2","",NULL);
#endif
 tolua_beginmodule(tolua_S,"Vector2");
 tolua_variable(tolua_S,"ZERO",tolua_get_Vector2_Vector2_ZERO,NULL);
 tolua_variable(tolua_S,"x",tolua_get_Vector2_Vector2_x,tolua_set_Vector2_Vector2_x);
 tolua_variable(tolua_S,"y",tolua_get_Vector2_Vector2_y,tolua_set_Vector2_Vector2_y);
 tolua_function(tolua_S,"assign",tolua_Aztec_Lua_Bind_Vector2_assign00);
 tolua_function(tolua_S,"equals",tolua_Aztec_Lua_Bind_Vector2_equals00);
 tolua_function(tolua_S,"set",tolua_Aztec_Lua_Bind_Vector2_set00);
 tolua_function(tolua_S,"add",tolua_Aztec_Lua_Bind_Vector2_add00);
 tolua_function(tolua_S,"sub",tolua_Aztec_Lua_Bind_Vector2_sub00);
 tolua_function(tolua_S,"new",tolua_Aztec_Lua_Bind_Vector2_new00);
 tolua_function(tolua_S,"new",tolua_Aztec_Lua_Bind_Vector2_new01);
 tolua_function(tolua_S,"delete",tolua_Aztec_Lua_Bind_Vector2_delete00);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"Transform","Transform","",tolua_collect_Transform);
#else
 tolua_cclass(tolua_S,"Transform","Transform","",NULL);
#endif
 tolua_beginmodule(tolua_S,"Transform");
 tolua_function(tolua_S,"new",tolua_Aztec_Lua_Bind_Transform_new00);
 tolua_function(tolua_S,"delete",tolua_Aztec_Lua_Bind_Transform_delete00);
 tolua_variable(tolua_S,"position",tolua_get_Transform_Transform_position,tolua_set_Transform_Transform_position);
 tolua_variable(tolua_S,"scale",tolua_get_Transform_Transform_scale,tolua_set_Transform_Transform_scale);
 tolua_variable(tolua_S,"rotation",tolua_get_Transform_Transform_rotation,tolua_set_Transform_Transform_rotation);
 tolua_variable(tolua_S,"zorder",tolua_get_Transform_Transform_zorder,tolua_set_Transform_Transform_zorder);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"Music","Music","LuaBinded",tolua_collect_Music);
#else
 tolua_cclass(tolua_S,"Music","Music","LuaBinded",NULL);
#endif
 tolua_beginmodule(tolua_S,"Music");
 tolua_function(tolua_S,"new",tolua_Aztec_Lua_Bind_Music_new00);
 tolua_function(tolua_S,"Play",tolua_Aztec_Lua_Bind_Music_Play00);
 tolua_function(tolua_S,"Stop",tolua_Aztec_Lua_Bind_Music_Stop00);
 tolua_function(tolua_S,"Pause",tolua_Aztec_Lua_Bind_Music_Pause00);
 tolua_function(tolua_S,"Resume",tolua_Aztec_Lua_Bind_Music_Resume00);
 tolua_function(tolua_S,"Seek",tolua_Aztec_Lua_Bind_Music_Seek00);
 tolua_function(tolua_S,"setVolume",tolua_Aztec_Lua_Bind_Music_setVolume00);
 tolua_variable(tolua_S,"Repeat",tolua_get_Music_Music_Repeat,tolua_set_Music_Music_Repeat);
 tolua_function(tolua_S,"isPlaying",tolua_Aztec_Lua_Bind_Music_isPlaying00);
 tolua_function(tolua_S,"delete",tolua_Aztec_Lua_Bind_Music_delete00);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"Sound","Sound","LuaBinded",tolua_collect_Sound);
#else
 tolua_cclass(tolua_S,"Sound","Sound","LuaBinded",NULL);
#endif
 tolua_beginmodule(tolua_S,"Sound");
 tolua_function(tolua_S,"new",tolua_Aztec_Lua_Bind_Sound_new00);
 tolua_function(tolua_S,"Play",tolua_Aztec_Lua_Bind_Sound_Play00);
 tolua_function(tolua_S,"delete",tolua_Aztec_Lua_Bind_Sound_delete00);
 tolua_endmodule(tolua_S);
 tolua_cclass(tolua_S,"Mouse","Mouse","",NULL);
 tolua_beginmodule(tolua_S,"Mouse");
 tolua_variable(tolua_S,"hasClick",tolua_get_Mouse_Mouse_hasClick,tolua_set_Mouse_Mouse_hasClick);
 tolua_variable(tolua_S,"hasMovement",tolua_get_Mouse_Mouse_hasMovement,tolua_set_Mouse_Mouse_hasMovement);
 tolua_function(tolua_S,"getPosX",tolua_Aztec_Lua_Bind_Mouse_getPosX00);
 tolua_function(tolua_S,"getPosY",tolua_Aztec_Lua_Bind_Mouse_getPosY00);
 tolua_function(tolua_S,"isLeftButtonPressed",tolua_Aztec_Lua_Bind_Mouse_isLeftButtonPressed00);
 tolua_function(tolua_S,"isMiddleButtonPressed",tolua_Aztec_Lua_Bind_Mouse_isMiddleButtonPressed00);
 tolua_function(tolua_S,"isRightButtonPressed",tolua_Aztec_Lua_Bind_Mouse_isRightButtonPressed00);
 tolua_function(tolua_S,"hideCursor",tolua_Aztec_Lua_Bind_Mouse_hideCursor00);
 tolua_function(tolua_S,"showCursor",tolua_Aztec_Lua_Bind_Mouse_showCursor00);
 tolua_endmodule(tolua_S);
 tolua_cclass(tolua_S,"Keyboard","Keyboard","",NULL);
 tolua_beginmodule(tolua_S,"Keyboard");
 tolua_variable(tolua_S,"UP_KEY",tolua_get_Keyboard_Keyboard_UP_KEY,NULL);
 tolua_variable(tolua_S,"DOWN_KEY",tolua_get_Keyboard_Keyboard_DOWN_KEY,NULL);
 tolua_variable(tolua_S,"RIGHT_KEY",tolua_get_Keyboard_Keyboard_RIGHT_KEY,NULL);
 tolua_variable(tolua_S,"LEFT_KEY",tolua_get_Keyboard_Keyboard_LEFT_KEY,NULL);
 tolua_variable(tolua_S,"ESCAPE_KEY",tolua_get_Keyboard_Keyboard_ESCAPE_KEY,NULL);
 tolua_variable(tolua_S,"SPACE_KEY",tolua_get_Keyboard_Keyboard_SPACE_KEY,NULL);
 tolua_variable(tolua_S,"ENTER_KEY",tolua_get_Keyboard_Keyboard_ENTER_KEY,NULL);
 tolua_variable(tolua_S,"zero",tolua_get_Keyboard_Keyboard_zero,NULL);
 tolua_variable(tolua_S,"one",tolua_get_Keyboard_Keyboard_one,NULL);
 tolua_variable(tolua_S,"two",tolua_get_Keyboard_Keyboard_two,NULL);
 tolua_variable(tolua_S,"three",tolua_get_Keyboard_Keyboard_three,NULL);
 tolua_variable(tolua_S,"four",tolua_get_Keyboard_Keyboard_four,NULL);
 tolua_variable(tolua_S,"five",tolua_get_Keyboard_Keyboard_five,NULL);
 tolua_variable(tolua_S,"six",tolua_get_Keyboard_Keyboard_six,NULL);
 tolua_variable(tolua_S,"seven",tolua_get_Keyboard_Keyboard_seven,NULL);
 tolua_variable(tolua_S,"eight",tolua_get_Keyboard_Keyboard_eight,NULL);
 tolua_variable(tolua_S,"nine",tolua_get_Keyboard_Keyboard_nine,NULL);
 tolua_variable(tolua_S,"KEY_UNKNOWN",tolua_get_Keyboard_Keyboard_KEY_UNKNOWN,NULL);
 tolua_variable(tolua_S,"KEY_FIND",tolua_get_Keyboard_Keyboard_KEY_FIND,NULL);
 tolua_variable(tolua_S,"KEY_BACKSPACE",tolua_get_Keyboard_Keyboard_KEY_BACKSPACE,NULL);
 tolua_variable(tolua_S,"KEY_TAB",tolua_get_Keyboard_Keyboard_KEY_TAB,NULL);
 tolua_variable(tolua_S,"KEY_CLEAR",tolua_get_Keyboard_Keyboard_KEY_CLEAR,NULL);
 tolua_variable(tolua_S,"KEY_RETURN",tolua_get_Keyboard_Keyboard_KEY_RETURN,NULL);
 tolua_variable(tolua_S,"KEY_PAUSE",tolua_get_Keyboard_Keyboard_KEY_PAUSE,NULL);
 tolua_variable(tolua_S,"KEY_ESCAPE",tolua_get_Keyboard_Keyboard_KEY_ESCAPE,NULL);
 tolua_variable(tolua_S,"KEY_SPACE",tolua_get_Keyboard_Keyboard_KEY_SPACE,NULL);
 tolua_variable(tolua_S,"KEY_EXCLAIM",tolua_get_Keyboard_Keyboard_KEY_EXCLAIM,NULL);
 tolua_variable(tolua_S,"KEY_QUOTEDBL",tolua_get_Keyboard_Keyboard_KEY_QUOTEDBL,NULL);
 tolua_variable(tolua_S,"KEY_HASH",tolua_get_Keyboard_Keyboard_KEY_HASH,NULL);
 tolua_variable(tolua_S,"KEY_DOLLAR",tolua_get_Keyboard_Keyboard_KEY_DOLLAR,NULL);
 tolua_variable(tolua_S,"KEY_AMPERSAND",tolua_get_Keyboard_Keyboard_KEY_AMPERSAND,NULL);
 tolua_variable(tolua_S,"KEY_QUOTE",tolua_get_Keyboard_Keyboard_KEY_QUOTE,NULL);
 tolua_variable(tolua_S,"KEY_LEFTPAREN",tolua_get_Keyboard_Keyboard_KEY_LEFTPAREN,NULL);
 tolua_variable(tolua_S,"KEY_RIGHTPAREN",tolua_get_Keyboard_Keyboard_KEY_RIGHTPAREN,NULL);
 tolua_variable(tolua_S,"KEY_ASTERISK",tolua_get_Keyboard_Keyboard_KEY_ASTERISK,NULL);
 tolua_variable(tolua_S,"KEY_PLUS",tolua_get_Keyboard_Keyboard_KEY_PLUS,NULL);
 tolua_variable(tolua_S,"KEY_COMMA",tolua_get_Keyboard_Keyboard_KEY_COMMA,NULL);
 tolua_variable(tolua_S,"KEY_MINUS",tolua_get_Keyboard_Keyboard_KEY_MINUS,NULL);
 tolua_variable(tolua_S,"KEY_PERIOD",tolua_get_Keyboard_Keyboard_KEY_PERIOD,NULL);
 tolua_variable(tolua_S,"KEY_SLASH",tolua_get_Keyboard_Keyboard_KEY_SLASH,NULL);
 tolua_variable(tolua_S,"KEY_0",tolua_get_Keyboard_Keyboard_KEY_0,NULL);
 tolua_variable(tolua_S,"KEY_1",tolua_get_Keyboard_Keyboard_KEY_1,NULL);
 tolua_variable(tolua_S,"KEY_2",tolua_get_Keyboard_Keyboard_KEY_2,NULL);
 tolua_variable(tolua_S,"KEY_3",tolua_get_Keyboard_Keyboard_KEY_3,NULL);
 tolua_variable(tolua_S,"KEY_4",tolua_get_Keyboard_Keyboard_KEY_4,NULL);
 tolua_variable(tolua_S,"KEY_5",tolua_get_Keyboard_Keyboard_KEY_5,NULL);
 tolua_variable(tolua_S,"KEY_6",tolua_get_Keyboard_Keyboard_KEY_6,NULL);
 tolua_variable(tolua_S,"KEY_7",tolua_get_Keyboard_Keyboard_KEY_7,NULL);
 tolua_variable(tolua_S,"KEY_8",tolua_get_Keyboard_Keyboard_KEY_8,NULL);
 tolua_variable(tolua_S,"KEY_9",tolua_get_Keyboard_Keyboard_KEY_9,NULL);
 tolua_variable(tolua_S,"KEY_COLON",tolua_get_Keyboard_Keyboard_KEY_COLON,NULL);
 tolua_variable(tolua_S,"KEY_SEMICOLON",tolua_get_Keyboard_Keyboard_KEY_SEMICOLON,NULL);
 tolua_variable(tolua_S,"KEY_LESS",tolua_get_Keyboard_Keyboard_KEY_LESS,NULL);
 tolua_variable(tolua_S,"KEY_EQUALS",tolua_get_Keyboard_Keyboard_KEY_EQUALS,NULL);
 tolua_variable(tolua_S,"KEY_GREATER",tolua_get_Keyboard_Keyboard_KEY_GREATER,NULL);
 tolua_variable(tolua_S,"KEY_QUESTION",tolua_get_Keyboard_Keyboard_KEY_QUESTION,NULL);
 tolua_variable(tolua_S,"KEY_AT",tolua_get_Keyboard_Keyboard_KEY_AT,NULL);
 tolua_variable(tolua_S,"KEY_LEFTBRACKET",tolua_get_Keyboard_Keyboard_KEY_LEFTBRACKET,NULL);
 tolua_variable(tolua_S,"KEY_BACKSLASH",tolua_get_Keyboard_Keyboard_KEY_BACKSLASH,NULL);
 tolua_variable(tolua_S,"KEY_RIGHTBRACKET",tolua_get_Keyboard_Keyboard_KEY_RIGHTBRACKET,NULL);
 tolua_variable(tolua_S,"KEY_CARET",tolua_get_Keyboard_Keyboard_KEY_CARET,NULL);
 tolua_variable(tolua_S,"KEY_UNDERSCORE",tolua_get_Keyboard_Keyboard_KEY_UNDERSCORE,NULL);
 tolua_variable(tolua_S,"KEY_BACKQUOTE",tolua_get_Keyboard_Keyboard_KEY_BACKQUOTE,NULL);
 tolua_variable(tolua_S,"KEY_a",tolua_get_Keyboard_Keyboard_KEY_a,NULL);
 tolua_variable(tolua_S,"KEY_b",tolua_get_Keyboard_Keyboard_KEY_b,NULL);
 tolua_variable(tolua_S,"KEY_c",tolua_get_Keyboard_Keyboard_KEY_c,NULL);
 tolua_variable(tolua_S,"KEY_d",tolua_get_Keyboard_Keyboard_KEY_d,NULL);
 tolua_variable(tolua_S,"KEY_e",tolua_get_Keyboard_Keyboard_KEY_e,NULL);
 tolua_variable(tolua_S,"KEY_f",tolua_get_Keyboard_Keyboard_KEY_f,NULL);
 tolua_variable(tolua_S,"KEY_g",tolua_get_Keyboard_Keyboard_KEY_g,NULL);
 tolua_variable(tolua_S,"KEY_h",tolua_get_Keyboard_Keyboard_KEY_h,NULL);
 tolua_variable(tolua_S,"KEY_i",tolua_get_Keyboard_Keyboard_KEY_i,NULL);
 tolua_variable(tolua_S,"KEY_j",tolua_get_Keyboard_Keyboard_KEY_j,NULL);
 tolua_variable(tolua_S,"KEY_k",tolua_get_Keyboard_Keyboard_KEY_k,NULL);
 tolua_variable(tolua_S,"KEY_l",tolua_get_Keyboard_Keyboard_KEY_l,NULL);
 tolua_variable(tolua_S,"KEY_m",tolua_get_Keyboard_Keyboard_KEY_m,NULL);
 tolua_variable(tolua_S,"KEY_n",tolua_get_Keyboard_Keyboard_KEY_n,NULL);
 tolua_variable(tolua_S,"KEY_o",tolua_get_Keyboard_Keyboard_KEY_o,NULL);
 tolua_variable(tolua_S,"KEY_p",tolua_get_Keyboard_Keyboard_KEY_p,NULL);
 tolua_variable(tolua_S,"KEY_q",tolua_get_Keyboard_Keyboard_KEY_q,NULL);
 tolua_variable(tolua_S,"KEY_r",tolua_get_Keyboard_Keyboard_KEY_r,NULL);
 tolua_variable(tolua_S,"KEY_s",tolua_get_Keyboard_Keyboard_KEY_s,NULL);
 tolua_variable(tolua_S,"KEY_t",tolua_get_Keyboard_Keyboard_KEY_t,NULL);
 tolua_variable(tolua_S,"KEY_u",tolua_get_Keyboard_Keyboard_KEY_u,NULL);
 tolua_variable(tolua_S,"KEY_v",tolua_get_Keyboard_Keyboard_KEY_v,NULL);
 tolua_variable(tolua_S,"KEY_w",tolua_get_Keyboard_Keyboard_KEY_w,NULL);
 tolua_variable(tolua_S,"KEY_x",tolua_get_Keyboard_Keyboard_KEY_x,NULL);
 tolua_variable(tolua_S,"KEY_y",tolua_get_Keyboard_Keyboard_KEY_y,NULL);
 tolua_variable(tolua_S,"KEY_z",tolua_get_Keyboard_Keyboard_KEY_z,NULL);
 tolua_variable(tolua_S,"KEY_DELETE",tolua_get_Keyboard_Keyboard_KEY_DELETE,NULL);
 tolua_variable(tolua_S,"KEY_KP0",tolua_get_Keyboard_Keyboard_KEY_KP0,NULL);
 tolua_variable(tolua_S,"KEY_KP1",tolua_get_Keyboard_Keyboard_KEY_KP1,NULL);
 tolua_variable(tolua_S,"KEY_KP2",tolua_get_Keyboard_Keyboard_KEY_KP2,NULL);
 tolua_variable(tolua_S,"KEY_KP3",tolua_get_Keyboard_Keyboard_KEY_KP3,NULL);
 tolua_variable(tolua_S,"KEY_KP4",tolua_get_Keyboard_Keyboard_KEY_KP4,NULL);
 tolua_variable(tolua_S,"KEY_KP5",tolua_get_Keyboard_Keyboard_KEY_KP5,NULL);
 tolua_variable(tolua_S,"KEY_KP6",tolua_get_Keyboard_Keyboard_KEY_KP6,NULL);
 tolua_variable(tolua_S,"KEY_KP7",tolua_get_Keyboard_Keyboard_KEY_KP7,NULL);
 tolua_variable(tolua_S,"KEY_KP8",tolua_get_Keyboard_Keyboard_KEY_KP8,NULL);
 tolua_variable(tolua_S,"KEY_KP9",tolua_get_Keyboard_Keyboard_KEY_KP9,NULL);
 tolua_variable(tolua_S,"KEY_KP_PERIOD",tolua_get_Keyboard_Keyboard_KEY_KP_PERIOD,NULL);
 tolua_variable(tolua_S,"KEY_KP_DIVIDE",tolua_get_Keyboard_Keyboard_KEY_KP_DIVIDE,NULL);
 tolua_variable(tolua_S,"KEY_KP_MULTIPLY",tolua_get_Keyboard_Keyboard_KEY_KP_MULTIPLY,NULL);
 tolua_variable(tolua_S,"KEY_KP_MINUS",tolua_get_Keyboard_Keyboard_KEY_KP_MINUS,NULL);
 tolua_variable(tolua_S,"KEY_KP_PLUS",tolua_get_Keyboard_Keyboard_KEY_KP_PLUS,NULL);
 tolua_variable(tolua_S,"KEY_KP_ENTER",tolua_get_Keyboard_Keyboard_KEY_KP_ENTER,NULL);
 tolua_variable(tolua_S,"KEY_KP_EQUALS",tolua_get_Keyboard_Keyboard_KEY_KP_EQUALS,NULL);
 tolua_variable(tolua_S,"KEY_UP",tolua_get_Keyboard_Keyboard_KEY_UP,NULL);
 tolua_variable(tolua_S,"KEY_DOWN",tolua_get_Keyboard_Keyboard_KEY_DOWN,NULL);
 tolua_variable(tolua_S,"KEY_RIGHT",tolua_get_Keyboard_Keyboard_KEY_RIGHT,NULL);
 tolua_variable(tolua_S,"KEY_LEFT",tolua_get_Keyboard_Keyboard_KEY_LEFT,NULL);
 tolua_variable(tolua_S,"KEY_INSERT",tolua_get_Keyboard_Keyboard_KEY_INSERT,NULL);
 tolua_variable(tolua_S,"KEY_HOME",tolua_get_Keyboard_Keyboard_KEY_HOME,NULL);
 tolua_variable(tolua_S,"KEY_END",tolua_get_Keyboard_Keyboard_KEY_END,NULL);
 tolua_variable(tolua_S,"KEY_ENTER",tolua_get_Keyboard_Keyboard_KEY_ENTER,NULL);
 tolua_variable(tolua_S,"KEY_PAGEUP",tolua_get_Keyboard_Keyboard_KEY_PAGEUP,NULL);
 tolua_variable(tolua_S,"KEY_PAGEDOWN",tolua_get_Keyboard_Keyboard_KEY_PAGEDOWN,NULL);
 tolua_variable(tolua_S,"KEY_F1",tolua_get_Keyboard_Keyboard_KEY_F1,NULL);
 tolua_variable(tolua_S,"KEY_F2",tolua_get_Keyboard_Keyboard_KEY_F2,NULL);
 tolua_variable(tolua_S,"KEY_F3",tolua_get_Keyboard_Keyboard_KEY_F3,NULL);
 tolua_variable(tolua_S,"KEY_F4",tolua_get_Keyboard_Keyboard_KEY_F4,NULL);
 tolua_variable(tolua_S,"KEY_F5",tolua_get_Keyboard_Keyboard_KEY_F5,NULL);
 tolua_variable(tolua_S,"KEY_F6",tolua_get_Keyboard_Keyboard_KEY_F6,NULL);
 tolua_variable(tolua_S,"KEY_F7",tolua_get_Keyboard_Keyboard_KEY_F7,NULL);
 tolua_variable(tolua_S,"KEY_F8",tolua_get_Keyboard_Keyboard_KEY_F8,NULL);
 tolua_variable(tolua_S,"KEY_F9",tolua_get_Keyboard_Keyboard_KEY_F9,NULL);
 tolua_variable(tolua_S,"KEY_F10",tolua_get_Keyboard_Keyboard_KEY_F10,NULL);
 tolua_variable(tolua_S,"KEY_F11",tolua_get_Keyboard_Keyboard_KEY_F11,NULL);
 tolua_variable(tolua_S,"KEY_F12",tolua_get_Keyboard_Keyboard_KEY_F12,NULL);
 tolua_variable(tolua_S,"KEY_F13",tolua_get_Keyboard_Keyboard_KEY_F13,NULL);
 tolua_variable(tolua_S,"KEY_F14",tolua_get_Keyboard_Keyboard_KEY_F14,NULL);
 tolua_variable(tolua_S,"KEY_F15",tolua_get_Keyboard_Keyboard_KEY_F15,NULL);
 tolua_variable(tolua_S,"KEY_NUMLOCK",tolua_get_Keyboard_Keyboard_KEY_NUMLOCK,NULL);
 tolua_variable(tolua_S,"KEY_CAPSLOCK",tolua_get_Keyboard_Keyboard_KEY_CAPSLOCK,NULL);
 tolua_variable(tolua_S,"KEY_SCROLLLOCK",tolua_get_Keyboard_Keyboard_KEY_SCROLLLOCK,NULL);
 tolua_variable(tolua_S,"KEY_RSHIFT",tolua_get_Keyboard_Keyboard_KEY_RSHIFT,NULL);
 tolua_variable(tolua_S,"KEY_LSHIFT",tolua_get_Keyboard_Keyboard_KEY_LSHIFT,NULL);
 tolua_variable(tolua_S,"KEY_RCTRL",tolua_get_Keyboard_Keyboard_KEY_RCTRL,NULL);
 tolua_variable(tolua_S,"KEY_LCTRL",tolua_get_Keyboard_Keyboard_KEY_LCTRL,NULL);
 tolua_variable(tolua_S,"KEY_RALT",tolua_get_Keyboard_Keyboard_KEY_RALT,NULL);
 tolua_variable(tolua_S,"KEY_LALT",tolua_get_Keyboard_Keyboard_KEY_LALT,NULL);
 tolua_variable(tolua_S,"KEY_MODE",tolua_get_Keyboard_Keyboard_KEY_MODE,NULL);
 tolua_variable(tolua_S,"KEY_HELP",tolua_get_Keyboard_Keyboard_KEY_HELP,NULL);
 tolua_variable(tolua_S,"KEY_PRINT",tolua_get_Keyboard_Keyboard_KEY_PRINT,NULL);
 tolua_variable(tolua_S,"KEY_SYSREQ",tolua_get_Keyboard_Keyboard_KEY_SYSREQ,NULL);
 tolua_variable(tolua_S,"KEY_MENU",tolua_get_Keyboard_Keyboard_KEY_MENU,NULL);
 tolua_variable(tolua_S,"KEY_POWER",tolua_get_Keyboard_Keyboard_KEY_POWER,NULL);
 tolua_variable(tolua_S,"KEY_UNDO",tolua_get_Keyboard_Keyboard_KEY_UNDO,NULL);
 tolua_function(tolua_S,"isShiftPressed",tolua_Aztec_Lua_Bind_Keyboard_isShiftPressed00);
 tolua_function(tolua_S,"isControlPressed",tolua_Aztec_Lua_Bind_Keyboard_isControlPressed00);
 tolua_function(tolua_S,"isAltPressed",tolua_Aztec_Lua_Bind_Keyboard_isAltPressed00);
 tolua_function(tolua_S,"keyIsDown",tolua_Aztec_Lua_Bind_Keyboard_keyIsDown00);
 tolua_function(tolua_S,"keyIsUp",tolua_Aztec_Lua_Bind_Keyboard_keyIsUp00);
 tolua_function(tolua_S,"bufferLength",tolua_Aztec_Lua_Bind_Keyboard_bufferLength00);
 tolua_function(tolua_S,"readBuffer",tolua_Aztec_Lua_Bind_Keyboard_readBuffer00);
 tolua_function(tolua_S,"cleanBuffer",tolua_Aztec_Lua_Bind_Keyboard_cleanBuffer00);
 tolua_function(tolua_S,"cleanPressed",tolua_Aztec_Lua_Bind_Keyboard_cleanPressed00);
 tolua_function(tolua_S,"reset",tolua_Aztec_Lua_Bind_Keyboard_reset00);
 tolua_endmodule(tolua_S);
 tolua_cclass(tolua_S,"GameObject","GameObject","LuaBinded",NULL);
 tolua_beginmodule(tolua_S,"GameObject");
 tolua_function(tolua_S,"new",tolua_Aztec_Lua_Bind_GameObject_new00);
 tolua_variable(tolua_S,"Transform",tolua_get_GameObject_GameObject_Transform,tolua_set_GameObject_GameObject_Transform);
 tolua_function(tolua_S,"getZOrder",tolua_Aztec_Lua_Bind_GameObject_getZOrder00);
 tolua_function(tolua_S,"setZOrder",tolua_Aztec_Lua_Bind_GameObject_setZOrder00);
 tolua_function(tolua_S,"getGlobalTransform",tolua_Aztec_Lua_Bind_GameObject_getGlobalTransform00);
 tolua_function(tolua_S,"getParent",tolua_Aztec_Lua_Bind_GameObject_getParent00);
 tolua_function(tolua_S,"addGameObject",tolua_Aztec_Lua_Bind_GameObject_addGameObject00);
 tolua_function(tolua_S,"removeGameObject",tolua_Aztec_Lua_Bind_GameObject_removeGameObject00);
 tolua_variable(tolua_S,"Visible",tolua_get_GameObject_GameObject_Visible,tolua_set_GameObject_GameObject_Visible);
 tolua_variable(tolua_S,"Enabled",tolua_get_GameObject_GameObject_Enabled,tolua_set_GameObject_GameObject_Enabled);
 tolua_function(tolua_S,"setPivot",tolua_Aztec_Lua_Bind_GameObject_setPivot00);
 tolua_function(tolua_S,"getPivot",tolua_Aztec_Lua_Bind_GameObject_getPivot00);
 tolua_function(tolua_S,"destroy",tolua_Aztec_Lua_Bind_GameObject_destroy00);
 tolua_function(tolua_S,"setClipRect",tolua_Aztec_Lua_Bind_GameObject_setClipRect00);
 tolua_function(tolua_S,"getLayerID",tolua_Aztec_Lua_Bind_GameObject_getLayerID00);
 tolua_function(tolua_S,"getLayer",tolua_Aztec_Lua_Bind_GameObject_getLayer00);
 tolua_function(tolua_S,"isLayer",tolua_Aztec_Lua_Bind_GameObject_isLayer00);
 tolua_function(tolua_S,"setProperty",tolua_Aztec_Lua_Bind_GameObject_setProperty00);
 tolua_function(tolua_S,"setProperty",tolua_Aztec_Lua_Bind_GameObject_setProperty01);
 tolua_function(tolua_S,"getProperty",tolua_Aztec_Lua_Bind_GameObject_getProperty00);
 tolua_function(tolua_S,"removeProperty",tolua_Aztec_Lua_Bind_GameObject_removeProperty00);
 tolua_function(tolua_S,"clearProperties",tolua_Aztec_Lua_Bind_GameObject_clearProperties00);
 tolua_function(tolua_S,"propertyAt",tolua_Aztec_Lua_Bind_GameObject_propertyAt00);
 tolua_function(tolua_S,"getPropertyName",tolua_Aztec_Lua_Bind_GameObject_getPropertyName00);
 tolua_function(tolua_S,"hasProperty",tolua_Aztec_Lua_Bind_GameObject_hasProperty00);
 tolua_function(tolua_S,"getPropertyCount",tolua_Aztec_Lua_Bind_GameObject_getPropertyCount00);
 tolua_function(tolua_S,"getGameState",tolua_Aztec_Lua_Bind_GameObject_getGameState00);
 tolua_endmodule(tolua_S);
 tolua_cclass(tolua_S,"Text","Text","GameObject",NULL);
 tolua_beginmodule(tolua_S,"Text");
 tolua_function(tolua_S,"new",tolua_Aztec_Lua_Bind_Text_new00);
 tolua_function(tolua_S,"new",tolua_Aztec_Lua_Bind_Text_new01);
 tolua_function(tolua_S,"setText",tolua_Aztec_Lua_Bind_Text_setText00);
 tolua_function(tolua_S,"getText",tolua_Aztec_Lua_Bind_Text_getText00);
 tolua_function(tolua_S,"setColor",tolua_Aztec_Lua_Bind_Text_setColor00);
 tolua_function(tolua_S,"setDimension",tolua_Aztec_Lua_Bind_Text_setDimension00);
 tolua_function(tolua_S,"selectByClick",tolua_Aztec_Lua_Bind_Text_selectByClick00);
 tolua_function(tolua_S,"setCursorPosition",tolua_Aztec_Lua_Bind_Text_setCursorPosition00);
 tolua_function(tolua_S,"getCursorPosition",tolua_Aztec_Lua_Bind_Text_getCursorPosition00);
 tolua_function(tolua_S,"getHeight",tolua_Aztec_Lua_Bind_Text_getHeight00);
 tolua_endmodule(tolua_S);
 tolua_cclass(tolua_S,"Frame","Frame","LuaBinded",NULL);
 tolua_beginmodule(tolua_S,"Frame");
 tolua_function(tolua_S,"new",tolua_Aztec_Lua_Bind_Frame_new00);
 tolua_function(tolua_S,"new",tolua_Aztec_Lua_Bind_Frame_new01);
 tolua_function(tolua_S,"new",tolua_Aztec_Lua_Bind_Frame_new02);
 tolua_endmodule(tolua_S);
 tolua_cclass(tolua_S,"Animation","Animation","LuaBinded",NULL);
 tolua_beginmodule(tolua_S,"Animation");
 tolua_variable(tolua_S,"Loop",tolua_get_Animation_Animation_Loop,tolua_set_Animation_Animation_Loop);
 tolua_variable(tolua_S,"Finished",tolua_get_Animation_Animation_Finished,tolua_set_Animation_Animation_Finished);
 tolua_variable(tolua_S,"Started",tolua_get_Animation_Animation_Started,tolua_set_Animation_Animation_Started);
 tolua_function(tolua_S,"getName",tolua_Aztec_Lua_Bind_Animation_getName00);
 tolua_function(tolua_S,"setFrame",tolua_Aztec_Lua_Bind_Animation_setFrame00);
 tolua_function(tolua_S,"getCurrentFrame",tolua_Aztec_Lua_Bind_Animation_getCurrentFrame00);
 tolua_function(tolua_S,"addFrame",tolua_Aztec_Lua_Bind_Animation_addFrame00);
 tolua_function(tolua_S,"addFrame",tolua_Aztec_Lua_Bind_Animation_addFrame01);
 tolua_function(tolua_S,"addFrame",tolua_Aztec_Lua_Bind_Animation_addFrame02);
 tolua_function(tolua_S,"addFrame",tolua_Aztec_Lua_Bind_Animation_addFrame03);
 tolua_function(tolua_S,"addHorizontalSequence",tolua_Aztec_Lua_Bind_Animation_addHorizontalSequence00);
 tolua_function(tolua_S,"addVerticalSequence",tolua_Aztec_Lua_Bind_Animation_addVerticalSequence00);
 tolua_function(tolua_S,"deleteAllFrames",tolua_Aztec_Lua_Bind_Animation_deleteAllFrames00);
 tolua_function(tolua_S,"setFrameInterval",tolua_Aztec_Lua_Bind_Animation_setFrameInterval00);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"Sensor","Sensor","GameObject",tolua_collect_Sensor);
#else
 tolua_cclass(tolua_S,"Sensor","Sensor","GameObject",NULL);
#endif
 tolua_beginmodule(tolua_S,"Sensor");
 tolua_function(tolua_S,"getTarget",tolua_Aztec_Lua_Bind_Sensor_getTarget00);
 tolua_function(tolua_S,"new",tolua_Aztec_Lua_Bind_Sensor_new00);
 tolua_function(tolua_S,"new",tolua_Aztec_Lua_Bind_Sensor_new01);
 tolua_function(tolua_S,"new",tolua_Aztec_Lua_Bind_Sensor_new02);
 tolua_function(tolua_S,"new",tolua_Aztec_Lua_Bind_Sensor_new03);
 tolua_function(tolua_S,"new",tolua_Aztec_Lua_Bind_Sensor_new04);
 tolua_function(tolua_S,"createFixture",tolua_Aztec_Lua_Bind_Sensor_createFixture00);
 tolua_function(tolua_S,"createFixture",tolua_Aztec_Lua_Bind_Sensor_createFixture01);
 tolua_function(tolua_S,"createFixture",tolua_Aztec_Lua_Bind_Sensor_createFixture02);
 tolua_function(tolua_S,"delete",tolua_Aztec_Lua_Bind_Sensor_delete00);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"PropertyList","PropertyList","LuaBinded",tolua_collect_PropertyList);
#else
 tolua_cclass(tolua_S,"PropertyList","PropertyList","LuaBinded",NULL);
#endif
 tolua_beginmodule(tolua_S,"PropertyList");
 tolua_function(tolua_S,"clear",tolua_Aztec_Lua_Bind_PropertyList_clear00);
 tolua_function(tolua_S,"add",tolua_Aztec_Lua_Bind_PropertyList_add00);
 tolua_function(tolua_S,"get",tolua_Aztec_Lua_Bind_PropertyList_get00);
 tolua_function(tolua_S,"at",tolua_Aztec_Lua_Bind_PropertyList_at00);
 tolua_function(tolua_S,"getName",tolua_Aztec_Lua_Bind_PropertyList_getName00);
 tolua_function(tolua_S,"getIndex",tolua_Aztec_Lua_Bind_PropertyList_getIndex00);
 tolua_function(tolua_S,"getValueIndex",tolua_Aztec_Lua_Bind_PropertyList_getValueIndex00);
 tolua_function(tolua_S,"getValueIndex",tolua_Aztec_Lua_Bind_PropertyList_getValueIndex01);
 tolua_function(tolua_S,"getSize",tolua_Aztec_Lua_Bind_PropertyList_getSize00);
 tolua_function(tolua_S,"set",tolua_Aztec_Lua_Bind_PropertyList_set00);
 tolua_function(tolua_S,"remove",tolua_Aztec_Lua_Bind_PropertyList_remove00);
 tolua_function(tolua_S,"has",tolua_Aztec_Lua_Bind_PropertyList_has00);
 tolua_function(tolua_S,"hasValue",tolua_Aztec_Lua_Bind_PropertyList_hasValue00);
 tolua_function(tolua_S,"new",tolua_Aztec_Lua_Bind_PropertyList_new00);
 tolua_function(tolua_S,"delete",tolua_Aztec_Lua_Bind_PropertyList_delete00);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"AutoSensor","AutoSensor","Sensor",tolua_collect_AutoSensor);
#else
 tolua_cclass(tolua_S,"AutoSensor","AutoSensor","Sensor",NULL);
#endif
 tolua_beginmodule(tolua_S,"AutoSensor");
 tolua_function(tolua_S,"new",tolua_Aztec_Lua_Bind_AutoSensor_new00);
 tolua_function(tolua_S,"new",tolua_Aztec_Lua_Bind_AutoSensor_new01);
 tolua_function(tolua_S,"new",tolua_Aztec_Lua_Bind_AutoSensor_new02);
 tolua_function(tolua_S,"new",tolua_Aztec_Lua_Bind_AutoSensor_new03);
 tolua_function(tolua_S,"delete",tolua_Aztec_Lua_Bind_AutoSensor_delete00);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"Shader","Shader","LuaBinded",tolua_collect_Shader);
#else
 tolua_cclass(tolua_S,"Shader","Shader","LuaBinded",NULL);
#endif
 tolua_beginmodule(tolua_S,"Shader");
 tolua_function(tolua_S,"SetUniform",tolua_Aztec_Lua_Bind_Shader_SetUniform00);
 tolua_function(tolua_S,"SetUniform",tolua_Aztec_Lua_Bind_Shader_SetUniform01);
 tolua_function(tolua_S,"SetUniform",tolua_Aztec_Lua_Bind_Shader_SetUniform02);
 tolua_function(tolua_S,"SetUniform",tolua_Aztec_Lua_Bind_Shader_SetUniform03);
 tolua_function(tolua_S,"SetUniformI",tolua_Aztec_Lua_Bind_Shader_SetUniformI00);
 tolua_function(tolua_S,"SetUniformI",tolua_Aztec_Lua_Bind_Shader_SetUniformI01);
 tolua_function(tolua_S,"SetUniformI",tolua_Aztec_Lua_Bind_Shader_SetUniformI02);
 tolua_function(tolua_S,"SetUniformI",tolua_Aztec_Lua_Bind_Shader_SetUniformI03);
 tolua_function(tolua_S,"SetUniformMatrix",tolua_Aztec_Lua_Bind_Shader_SetUniformMatrix00);
 tolua_function(tolua_S,"createFromFiles",tolua_Aztec_Lua_Bind_Shader_createFromFiles00);
 tolua_function(tolua_S,"createFromSource",tolua_Aztec_Lua_Bind_Shader_createFromSource00);
 tolua_function(tolua_S,"createDefaultShader",tolua_Aztec_Lua_Bind_Shader_createDefaultShader00);
 tolua_function(tolua_S,"delete",tolua_Aztec_Lua_Bind_Shader_delete00);
 tolua_endmodule(tolua_S);
 tolua_cclass(tolua_S,"Sprite","Sprite","GameObject",NULL);
 tolua_beginmodule(tolua_S,"Sprite");
 tolua_function(tolua_S,"new",tolua_Aztec_Lua_Bind_Sprite_new00);
 tolua_function(tolua_S,"new",tolua_Aztec_Lua_Bind_Sprite_new01);
 tolua_function(tolua_S,"new",tolua_Aztec_Lua_Bind_Sprite_new02);
 tolua_function(tolua_S,"new",tolua_Aztec_Lua_Bind_Sprite_new03);
 tolua_function(tolua_S,"new",tolua_Aztec_Lua_Bind_Sprite_new04);
 tolua_function(tolua_S,"new",tolua_Aztec_Lua_Bind_Sprite_new05);
 tolua_function(tolua_S,"new",tolua_Aztec_Lua_Bind_Sprite_new06);
 tolua_function(tolua_S,"setFlipped",tolua_Aztec_Lua_Bind_Sprite_setFlipped00);
 tolua_function(tolua_S,"setVerticalFlipped",tolua_Aztec_Lua_Bind_Sprite_setVerticalFlipped00);
 tolua_function(tolua_S,"getFlipped",tolua_Aztec_Lua_Bind_Sprite_getFlipped00);
 tolua_function(tolua_S,"getVerticalFlipped",tolua_Aztec_Lua_Bind_Sprite_getVerticalFlipped00);
 tolua_function(tolua_S,"setFrameInterval",tolua_Aztec_Lua_Bind_Sprite_setFrameInterval00);
 tolua_function(tolua_S,"getFrameInterval",tolua_Aztec_Lua_Bind_Sprite_getFrameInterval00);
 tolua_function(tolua_S,"pivotOnCenter",tolua_Aztec_Lua_Bind_Sprite_pivotOnCenter00);
 tolua_function(tolua_S,"newAnimation",tolua_Aztec_Lua_Bind_Sprite_newAnimation00);
 tolua_function(tolua_S,"removeAnimation",tolua_Aztec_Lua_Bind_Sprite_removeAnimation00);
 tolua_function(tolua_S,"setAnimation",tolua_Aztec_Lua_Bind_Sprite_setAnimation00);
 tolua_function(tolua_S,"setAnimation",tolua_Aztec_Lua_Bind_Sprite_setAnimation01);
 tolua_function(tolua_S,"getCurrentAnimation",tolua_Aztec_Lua_Bind_Sprite_getCurrentAnimation00);
 tolua_function(tolua_S,"setShader",tolua_Aztec_Lua_Bind_Sprite_setShader00);
 tolua_function(tolua_S,"getShader",tolua_Aztec_Lua_Bind_Sprite_getShader00);
 tolua_function(tolua_S,"getPlane",tolua_Aztec_Lua_Bind_Sprite_getPlane00);
 tolua_function(tolua_S,"createSensor",tolua_Aztec_Lua_Bind_Sprite_createSensor00);
 tolua_function(tolua_S,"createCircleSensor",tolua_Aztec_Lua_Bind_Sprite_createCircleSensor00);
 tolua_function(tolua_S,"destroySensor",tolua_Aztec_Lua_Bind_Sprite_destroySensor00);
 tolua_endmodule(tolua_S);
 tolua_cclass(tolua_S,"SpriteSensor","SpriteSensor","Sprite",NULL);
 tolua_beginmodule(tolua_S,"SpriteSensor");
 tolua_function(tolua_S,"new",tolua_Aztec_Lua_Bind_SpriteSensor_new00);
 tolua_function(tolua_S,"new",tolua_Aztec_Lua_Bind_SpriteSensor_new01);
 tolua_function(tolua_S,"new",tolua_Aztec_Lua_Bind_SpriteSensor_new02);
 tolua_function(tolua_S,"new",tolua_Aztec_Lua_Bind_SpriteSensor_new03);
 tolua_function(tolua_S,"new",tolua_Aztec_Lua_Bind_SpriteSensor_new04);
 tolua_function(tolua_S,"new",tolua_Aztec_Lua_Bind_SpriteSensor_new05);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"GameStateController","GameStateController","LuaBinded",tolua_collect_GameStateController);
#else
 tolua_cclass(tolua_S,"GameStateController","GameStateController","LuaBinded",NULL);
#endif
 tolua_beginmodule(tolua_S,"GameStateController");
 tolua_function(tolua_S,"new",tolua_Aztec_Lua_Bind_GameStateController_new00);
 tolua_function(tolua_S,"new",tolua_Aztec_Lua_Bind_GameStateController_new01);
 tolua_function(tolua_S,"delete",tolua_Aztec_Lua_Bind_GameStateController_delete00);
 tolua_function(tolua_S,"load",tolua_Aztec_Lua_Bind_GameStateController_load00);
 tolua_function(tolua_S,"queryProperty",tolua_Aztec_Lua_Bind_GameStateController_queryProperty00);
 tolua_function(tolua_S,"queryProperty",tolua_Aztec_Lua_Bind_GameStateController_queryProperty01);
 tolua_function(tolua_S,"getActiveCamera",tolua_Aztec_Lua_Bind_GameStateController_getActiveCamera00);
 tolua_function(tolua_S,"addOverlay",tolua_Aztec_Lua_Bind_GameStateController_addOverlay00);
 tolua_function(tolua_S,"removeOverlay",tolua_Aztec_Lua_Bind_GameStateController_removeOverlay00);
 tolua_function(tolua_S,"addBackDrops",tolua_Aztec_Lua_Bind_GameStateController_addBackDrops00);
 tolua_function(tolua_S,"removeBackDrops",tolua_Aztec_Lua_Bind_GameStateController_removeBackDrops00);
 tolua_function(tolua_S,"addTile",tolua_Aztec_Lua_Bind_GameStateController_addTile00);
 tolua_function(tolua_S,"removeTile",tolua_Aztec_Lua_Bind_GameStateController_removeTile00);
 tolua_function(tolua_S,"add",tolua_Aztec_Lua_Bind_GameStateController_add00);
 tolua_function(tolua_S,"add",tolua_Aztec_Lua_Bind_GameStateController_add01);
 tolua_function(tolua_S,"remove",tolua_Aztec_Lua_Bind_GameStateController_remove00);
 tolua_function(tolua_S,"getLayer",tolua_Aztec_Lua_Bind_GameStateController_getLayer00);
 tolua_function(tolua_S,"setProperty",tolua_Aztec_Lua_Bind_GameStateController_setProperty00);
 tolua_function(tolua_S,"getProperty",tolua_Aztec_Lua_Bind_GameStateController_getProperty00);
 tolua_function(tolua_S,"removeProperty",tolua_Aztec_Lua_Bind_GameStateController_removeProperty00);
 tolua_function(tolua_S,"clearProperties",tolua_Aztec_Lua_Bind_GameStateController_clearProperties00);
 tolua_function(tolua_S,"propertyAt",tolua_Aztec_Lua_Bind_GameStateController_propertyAt00);
 tolua_function(tolua_S,"getPropertyName",tolua_Aztec_Lua_Bind_GameStateController_getPropertyName00);
 tolua_function(tolua_S,"hasProperty",tolua_Aztec_Lua_Bind_GameStateController_hasProperty00);
 tolua_function(tolua_S,"getPropertyCount",tolua_Aztec_Lua_Bind_GameStateController_getPropertyCount00);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"GameObjectList","GameObjectList","LuaBinded",tolua_collect_GameObjectList);
#else
 tolua_cclass(tolua_S,"GameObjectList","GameObjectList","LuaBinded",NULL);
#endif
 tolua_beginmodule(tolua_S,"GameObjectList");
 tolua_function(tolua_S,"clear",tolua_Aztec_Lua_Bind_GameObjectList_clear00);
 tolua_function(tolua_S,"add",tolua_Aztec_Lua_Bind_GameObjectList_add00);
 tolua_function(tolua_S,"get",tolua_Aztec_Lua_Bind_GameObjectList_get00);
 tolua_function(tolua_S,"at",tolua_Aztec_Lua_Bind_GameObjectList_at00);
 tolua_function(tolua_S,"getSize",tolua_Aztec_Lua_Bind_GameObjectList_getSize00);
 tolua_function(tolua_S,"remove",tolua_Aztec_Lua_Bind_GameObjectList_remove00);
 tolua_function(tolua_S,"has",tolua_Aztec_Lua_Bind_GameObjectList_has00);
 tolua_function(tolua_S,"setPosition",tolua_Aztec_Lua_Bind_GameObjectList_setPosition00);
 tolua_function(tolua_S,"hasNext",tolua_Aztec_Lua_Bind_GameObjectList_hasNext00);
 tolua_function(tolua_S,"next",tolua_Aztec_Lua_Bind_GameObjectList_next00);
 tolua_function(tolua_S,"new",tolua_Aztec_Lua_Bind_GameObjectList_new00);
 tolua_function(tolua_S,"delete",tolua_Aztec_Lua_Bind_GameObjectList_delete00);
 tolua_endmodule(tolua_S);
 tolua_cclass(tolua_S,"Config","Config","",NULL);
 tolua_beginmodule(tolua_S,"Config");
 tolua_variable(tolua_S,"TITLE",tolua_get_Config_Config_TITLE,tolua_set_Config_Config_TITLE);
 tolua_variable(tolua_S,"SCREEN_WIDTH",tolua_get_Config_Config_SCREEN_WIDTH,tolua_set_Config_Config_SCREEN_WIDTH);
 tolua_variable(tolua_S,"SCREEN_HEIGHT",tolua_get_Config_Config_SCREEN_HEIGHT,tolua_set_Config_Config_SCREEN_HEIGHT);
 tolua_variable(tolua_S,"FULLSCREEN",tolua_get_Config_Config_FULLSCREEN,tolua_set_Config_Config_FULLSCREEN);
 tolua_variable(tolua_S,"DEBUG_DRAW",tolua_get_Config_Config_DEBUG_DRAW,tolua_set_Config_Config_DEBUG_DRAW);
 tolua_variable(tolua_S,"SOUND_CHANNELS",tolua_get_Config_Config_SOUND_CHANNELS,tolua_set_Config_Config_SOUND_CHANNELS);
 tolua_variable(tolua_S,"SOUND_FREQUENCY",tolua_get_Config_Config_SOUND_FREQUENCY,tolua_set_Config_Config_SOUND_FREQUENCY);
 tolua_variable(tolua_S,"SOUND_BUFFER_SIZE",tolua_get_Config_Config_SOUND_BUFFER_SIZE,tolua_set_Config_Config_SOUND_BUFFER_SIZE);
 tolua_variable(tolua_S,"PHYSICS_PIXELS_METERS_RATIO",tolua_get_Config_Config_PHYSICS_PIXELS_METERS_RATIO,tolua_set_Config_Config_PHYSICS_PIXELS_METERS_RATIO);
 tolua_endmodule(tolua_S);
 tolua_cclass(tolua_S,"Camera","Camera","GameObject",NULL);
 tolua_beginmodule(tolua_S,"Camera");
 tolua_function(tolua_S,"new",tolua_Aztec_Lua_Bind_Camera_new00);
 tolua_function(tolua_S,"activate",tolua_Aztec_Lua_Bind_Camera_activate00);
 tolua_function(tolua_S,"deactivate",tolua_Aztec_Lua_Bind_Camera_deactivate00);
 tolua_function(tolua_S,"centerOnScreen",tolua_Aztec_Lua_Bind_Camera_centerOnScreen00);
 tolua_function(tolua_S,"setColorBalance",tolua_Aztec_Lua_Bind_Camera_setColorBalance00);
 tolua_endmodule(tolua_S);
 tolua_cclass(tolua_S,"GameEngine","GameEngine","",NULL);
 tolua_beginmodule(tolua_S,"GameEngine");
 tolua_function(tolua_S,"SetOffscreenRenderer",tolua_Aztec_Lua_Bind_GameEngine_SetOffscreenRenderer00);
 tolua_variable(tolua_S,"Arguments",tolua_get_GameEngine_GameEngine_Arguments_ptr,tolua_set_GameEngine_GameEngine_Arguments_ptr);
 tolua_function(tolua_S,"getInstance",tolua_Aztec_Lua_Bind_GameEngine_getInstance00);
 tolua_function(tolua_S,"freeInstance",tolua_Aztec_Lua_Bind_GameEngine_freeInstance00);
 tolua_function(tolua_S,"requestShutdown",tolua_Aztec_Lua_Bind_GameEngine_requestShutdown00);
 tolua_function(tolua_S,"getCurrentGameState",tolua_Aztec_Lua_Bind_GameEngine_getCurrentGameState00);
 tolua_function(tolua_S,"run",tolua_Aztec_Lua_Bind_GameEngine_run00);
 tolua_function(tolua_S,"run",tolua_Aztec_Lua_Bind_GameEngine_run01);
 tolua_function(tolua_S,"getKeyboard",tolua_Aztec_Lua_Bind_GameEngine_getKeyboard00);
 tolua_function(tolua_S,"getMouse",tolua_Aztec_Lua_Bind_GameEngine_getMouse00);
 tolua_function(tolua_S,"getElapsedTime",tolua_Aztec_Lua_Bind_GameEngine_getElapsedTime00);
 tolua_function(tolua_S,"getTrueElapsedTime",tolua_Aztec_Lua_Bind_GameEngine_getTrueElapsedTime00);
 tolua_function(tolua_S,"getCurrentTime",tolua_Aztec_Lua_Bind_GameEngine_getCurrentTime00);
 tolua_function(tolua_S,"getTrueCurrentTime",tolua_Aztec_Lua_Bind_GameEngine_getTrueCurrentTime00);
 tolua_endmodule(tolua_S);
 tolua_cclass(tolua_S,"EventTypes","EventTypes","",NULL);
 tolua_beginmodule(tolua_S,"EventTypes");
 tolua_variable(tolua_S,"NONE",tolua_get_EventTypes_EventTypes_NONE,NULL);
 tolua_variable(tolua_S,"OnUpdate",tolua_get_EventTypes_EventTypes_OnUpdate,NULL);
 tolua_variable(tolua_S,"OnClick",tolua_get_EventTypes_EventTypes_OnClick,NULL);
 tolua_variable(tolua_S,"OnMouseMove",tolua_get_EventTypes_EventTypes_OnMouseMove,NULL);
 tolua_variable(tolua_S,"OnMouseDown",tolua_get_EventTypes_EventTypes_OnMouseDown,NULL);
 tolua_variable(tolua_S,"OnMouseUp",tolua_get_EventTypes_EventTypes_OnMouseUp,NULL);
 tolua_variable(tolua_S,"OnKeyDown",tolua_get_EventTypes_EventTypes_OnKeyDown,NULL);
 tolua_variable(tolua_S,"OnKeyUp",tolua_get_EventTypes_EventTypes_OnKeyUp,NULL);
 tolua_variable(tolua_S,"OnBeginContact",tolua_get_EventTypes_EventTypes_OnBeginContact,NULL);
 tolua_variable(tolua_S,"OnEndContact",tolua_get_EventTypes_EventTypes_OnEndContact,NULL);
 tolua_variable(tolua_S,"OnMusicStarted",tolua_get_EventTypes_EventTypes_OnMusicStarted,NULL);
 tolua_variable(tolua_S,"OnMusicFinished",tolua_get_EventTypes_EventTypes_OnMusicFinished,NULL);
 tolua_variable(tolua_S,"OnAnimationStarted",tolua_get_EventTypes_EventTypes_OnAnimationStarted,NULL);
 tolua_variable(tolua_S,"OnAnimationFinished",tolua_get_EventTypes_EventTypes_OnAnimationFinished,NULL);
 tolua_variable(tolua_S,"OnBeforeDraw",tolua_get_EventTypes_EventTypes_OnBeforeDraw,NULL);
 tolua_variable(tolua_S,"OnAfterDraw",tolua_get_EventTypes_EventTypes_OnAfterDraw,NULL);
 tolua_variable(tolua_S,"ALL",tolua_get_EventTypes_EventTypes_ALL,NULL);
 tolua_endmodule(tolua_S);
 tolua_cclass(tolua_S,"Bitwise","Bitwise","",NULL);
 tolua_beginmodule(tolua_S,"Bitwise");
 tolua_function(tolua_S,"XOR",tolua_Aztec_Lua_Bind_Bitwise_XOR00);
 tolua_function(tolua_S,"AND",tolua_Aztec_Lua_Bind_Bitwise_AND00);
 tolua_function(tolua_S,"OR",tolua_Aztec_Lua_Bind_Bitwise_OR00);
 tolua_function(tolua_S,"NOT",tolua_Aztec_Lua_Bind_Bitwise_NOT00);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"Texture","Texture","LuaBinded",tolua_collect_Texture);
#else
 tolua_cclass(tolua_S,"Texture","Texture","LuaBinded",NULL);
#endif
 tolua_beginmodule(tolua_S,"Texture");
 tolua_variable(tolua_S,"DIFFUSE",tolua_get_Texture_Texture_unsigned_DIFFUSE,NULL);
 tolua_variable(tolua_S,"NORMAL",tolua_get_Texture_Texture_unsigned_NORMAL,NULL);
 tolua_variable(tolua_S,"TEXTURE0",tolua_get_Texture_Texture_unsigned_TEXTURE0,NULL);
 tolua_variable(tolua_S,"TEXTURE1",tolua_get_Texture_Texture_unsigned_TEXTURE1,NULL);
 tolua_variable(tolua_S,"TEXTURE2",tolua_get_Texture_Texture_unsigned_TEXTURE2,NULL);
 tolua_variable(tolua_S,"TEXTURE3",tolua_get_Texture_Texture_unsigned_TEXTURE3,NULL);
 tolua_variable(tolua_S,"TEXTURE4",tolua_get_Texture_Texture_unsigned_TEXTURE4,NULL);
 tolua_variable(tolua_S,"TEXTURE5",tolua_get_Texture_Texture_unsigned_TEXTURE5,NULL);
 tolua_variable(tolua_S,"TEXTURE6",tolua_get_Texture_Texture_unsigned_TEXTURE6,NULL);
 tolua_variable(tolua_S,"TEXTURE7",tolua_get_Texture_Texture_unsigned_TEXTURE7,NULL);
 tolua_variable(tolua_S,"TEXTURE8",tolua_get_Texture_Texture_unsigned_TEXTURE8,NULL);
 tolua_function(tolua_S,"new",tolua_Aztec_Lua_Bind_Texture_new00);
 tolua_function(tolua_S,"getWidth",tolua_Aztec_Lua_Bind_Texture_getWidth00);
 tolua_function(tolua_S,"getHeight",tolua_Aztec_Lua_Bind_Texture_getHeight00);
 tolua_function(tolua_S,"getOriginalWidth",tolua_Aztec_Lua_Bind_Texture_getOriginalWidth00);
 tolua_function(tolua_S,"getOriginalHeight",tolua_Aztec_Lua_Bind_Texture_getOriginalHeight00);
 tolua_function(tolua_S,"getPath",tolua_Aztec_Lua_Bind_Texture_getPath00);
 tolua_function(tolua_S,"getTextureID",tolua_Aztec_Lua_Bind_Texture_getTextureID00);
 tolua_function(tolua_S,"delete",tolua_Aztec_Lua_Bind_Texture_delete00);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"Shape","Shape","",tolua_collect_Shape);
#else
 tolua_cclass(tolua_S,"Shape","Shape","",NULL);
#endif
 tolua_beginmodule(tolua_S,"Shape");
 tolua_variable(tolua_S,"DRAW_QUADS",tolua_get_Shape_Shape_DRAW_QUADS,NULL);
 tolua_variable(tolua_S,"DRAW_TRIANGLES",tolua_get_Shape_Shape_DRAW_TRIANGLES,NULL);
 tolua_variable(tolua_S,"DRAW_TRIANGLE_FAN",tolua_get_Shape_Shape_DRAW_TRIANGLE_FAN,NULL);
 tolua_variable(tolua_S,"DRAW_LINES",tolua_get_Shape_Shape_DRAW_LINES,NULL);
 tolua_variable(tolua_S,"DRAW_POINTS",tolua_get_Shape_Shape_DRAW_POINTS,NULL);
 tolua_function(tolua_S,"setDrawMode",tolua_Aztec_Lua_Bind_Shape_setDrawMode00);
 tolua_function(tolua_S,"setFillMode",tolua_Aztec_Lua_Bind_Shape_setFillMode00);
 tolua_function(tolua_S,"setColorBalance",tolua_Aztec_Lua_Bind_Shape_setColorBalance00);
 tolua_function(tolua_S,"new",tolua_Aztec_Lua_Bind_Shape_new00);
 tolua_function(tolua_S,"new",tolua_Aztec_Lua_Bind_Shape_new01);
 tolua_function(tolua_S,"setShader",tolua_Aztec_Lua_Bind_Shape_setShader00);
 tolua_function(tolua_S,"getShader",tolua_Aztec_Lua_Bind_Shape_getShader00);
 tolua_function(tolua_S,"getVAO",tolua_Aztec_Lua_Bind_Shape_getVAO00);
 tolua_function(tolua_S,"setVAO",tolua_Aztec_Lua_Bind_Shape_setVAO00);
 tolua_function(tolua_S,"setTranslation",tolua_Aztec_Lua_Bind_Shape_setTranslation00);
 tolua_function(tolua_S,"setPivot",tolua_Aztec_Lua_Bind_Shape_setPivot00);
 tolua_function(tolua_S,"setRotation",tolua_Aztec_Lua_Bind_Shape_setRotation00);
 tolua_function(tolua_S,"setPostRotation",tolua_Aztec_Lua_Bind_Shape_setPostRotation00);
 tolua_function(tolua_S,"setScale",tolua_Aztec_Lua_Bind_Shape_setScale00);
 tolua_function(tolua_S,"setScale",tolua_Aztec_Lua_Bind_Shape_setScale01);
 tolua_function(tolua_S,"getTexture",tolua_Aztec_Lua_Bind_Shape_getTexture00);
 tolua_function(tolua_S,"setTexture",tolua_Aztec_Lua_Bind_Shape_setTexture00);
 tolua_function(tolua_S,"delete",tolua_Aztec_Lua_Bind_Shape_delete00);
 tolua_function(tolua_S,"Draw",tolua_Aztec_Lua_Bind_Shape_Draw00);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"Plane","Plane","Shape",tolua_collect_Plane);
#else
 tolua_cclass(tolua_S,"Plane","Plane","Shape",NULL);
#endif
 tolua_beginmodule(tolua_S,"Plane");
 tolua_function(tolua_S,"new",tolua_Aztec_Lua_Bind_Plane_new00);
 tolua_function(tolua_S,"new",tolua_Aztec_Lua_Bind_Plane_new01);
 tolua_function(tolua_S,"delete",tolua_Aztec_Lua_Bind_Plane_delete00);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"VertexBufferObject","VertexBufferObject","",tolua_collect_VertexBufferObject);
#else
 tolua_cclass(tolua_S,"VertexBufferObject","VertexBufferObject","",NULL);
#endif
 tolua_beginmodule(tolua_S,"VertexBufferObject");
 tolua_function(tolua_S,"new",tolua_Aztec_Lua_Bind_VertexBufferObject_new00);
 tolua_function(tolua_S,"delete",tolua_Aztec_Lua_Bind_VertexBufferObject_delete00);
 tolua_function(tolua_S,"getCount",tolua_Aztec_Lua_Bind_VertexBufferObject_getCount00);
 tolua_function(tolua_S,"getVBO",tolua_Aztec_Lua_Bind_VertexBufferObject_getVBO00);
 tolua_function(tolua_S,"getBufferSize",tolua_Aztec_Lua_Bind_VertexBufferObject_getBufferSize00);
 tolua_function(tolua_S,"getElementSize",tolua_Aztec_Lua_Bind_VertexBufferObject_getElementSize00);
 tolua_function(tolua_S,"bindBuffer",tolua_Aztec_Lua_Bind_VertexBufferObject_bindBuffer00);
 tolua_function(tolua_S,"bindBuffer",tolua_Aztec_Lua_Bind_VertexBufferObject_bindBuffer01);
 tolua_function(tolua_S,"updateBuffer",tolua_Aztec_Lua_Bind_VertexBufferObject_updateBuffer00);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"VertexArrayObject","VertexArrayObject","LuaBinded",tolua_collect_VertexArrayObject);
#else
 tolua_cclass(tolua_S,"VertexArrayObject","VertexArrayObject","LuaBinded",NULL);
#endif
 tolua_beginmodule(tolua_S,"VertexArrayObject");
 tolua_function(tolua_S,"new",tolua_Aztec_Lua_Bind_VertexArrayObject_new00);
 tolua_function(tolua_S,"delete",tolua_Aztec_Lua_Bind_VertexArrayObject_delete00);
 tolua_function(tolua_S,"addVBO",tolua_Aztec_Lua_Bind_VertexArrayObject_addVBO00);
 tolua_function(tolua_S,"getVBO",tolua_Aztec_Lua_Bind_VertexArrayObject_getVBO00);
 tolua_function(tolua_S,"generate",tolua_Aztec_Lua_Bind_VertexArrayObject_generate00);
 tolua_function(tolua_S,"getId",tolua_Aztec_Lua_Bind_VertexArrayObject_getId00);
 tolua_endmodule(tolua_S);
 tolua_cclass(tolua_S,"WebBrowser","WebBrowser","GameObject",NULL);
 tolua_beginmodule(tolua_S,"WebBrowser");
 tolua_function(tolua_S,"new",tolua_Aztec_Lua_Bind_WebBrowser_new00);
 tolua_function(tolua_S,"new",tolua_Aztec_Lua_Bind_WebBrowser_new01);
 tolua_function(tolua_S,"new",tolua_Aztec_Lua_Bind_WebBrowser_new02);
 tolua_function(tolua_S,"Navigate",tolua_Aztec_Lua_Bind_WebBrowser_Navigate00);
 tolua_function(tolua_S,"GoBack",tolua_Aztec_Lua_Bind_WebBrowser_GoBack00);
 tolua_function(tolua_S,"GoForward",tolua_Aztec_Lua_Bind_WebBrowser_GoForward00);
 tolua_function(tolua_S,"Stop",tolua_Aztec_Lua_Bind_WebBrowser_Stop00);
 tolua_function(tolua_S,"isLoading",tolua_Aztec_Lua_Bind_WebBrowser_isLoading00);
 tolua_function(tolua_S,"Refresh",tolua_Aztec_Lua_Bind_WebBrowser_Refresh00);
 tolua_function(tolua_S,"setAlwaysFocused",tolua_Aztec_Lua_Bind_WebBrowser_setAlwaysFocused00);
 tolua_function(tolua_S,"getAlwaysFocused",tolua_Aztec_Lua_Bind_WebBrowser_getAlwaysFocused00);
 tolua_function(tolua_S,"setShader",tolua_Aztec_Lua_Bind_WebBrowser_setShader00);
 tolua_function(tolua_S,"getShader",tolua_Aztec_Lua_Bind_WebBrowser_getShader00);
 tolua_function(tolua_S,"getPlane",tolua_Aztec_Lua_Bind_WebBrowser_getPlane00);
 tolua_function(tolua_S,"ExecuteScript",tolua_Aztec_Lua_Bind_WebBrowser_ExecuteScript00);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"PointList2D","PointList2D","LuaBinded",tolua_collect_PointList2D);
#else
 tolua_cclass(tolua_S,"PointList2D","PointList2D","LuaBinded",NULL);
#endif
 tolua_beginmodule(tolua_S,"PointList2D");
 tolua_function(tolua_S,"clear",tolua_Aztec_Lua_Bind_PointList2D_clear00);
 tolua_function(tolua_S,"clear",tolua_Aztec_Lua_Bind_PointList2D_clear01);
 tolua_function(tolua_S,"add",tolua_Aztec_Lua_Bind_PointList2D_add00);
 tolua_function(tolua_S,"add",tolua_Aztec_Lua_Bind_PointList2D_add01);
 tolua_function(tolua_S,"get",tolua_Aztec_Lua_Bind_PointList2D_get00);
 tolua_function(tolua_S,"set",tolua_Aztec_Lua_Bind_PointList2D_set00);
 tolua_function(tolua_S,"set",tolua_Aztec_Lua_Bind_PointList2D_set01);
 tolua_function(tolua_S,"remove",tolua_Aztec_Lua_Bind_PointList2D_remove00);
 tolua_function(tolua_S,"new",tolua_Aztec_Lua_Bind_PointList2D_new00);
 tolua_function(tolua_S,"delete",tolua_Aztec_Lua_Bind_PointList2D_delete00);
 tolua_endmodule(tolua_S);

 { /* begin embedded lua code */
 static unsigned char B[] = {
  10,108,111, 99, 97,108, 32,109, 97,116,104, 32, 61, 32,114,
 101,113,117,105,114,101, 40, 39,109, 97,116,104, 39, 41, 10,
 108,111, 99, 97,108, 32,115,116,114,105,110,103, 32, 61, 32,
 114,101,113,117,105,114,101, 40, 34,115,116,114,105,110,103,
  34, 41, 10,108,111, 99, 97,108, 32,116, 97, 98,108,101, 32,
  61, 32,114,101,113,117,105,114,101, 40, 34,116, 97, 98,108,
 101, 34, 41, 10,106,115,111,110, 32, 61, 32,123,125, 10,108,
 111, 99, 97,108, 32,106,115,111,110, 95,112,114,105,118, 97,
 116,101, 32, 61, 32,123,125, 10,108,111, 99, 97,108, 32,100,
 101, 99,111,100,101, 95,115, 99, 97,110, 65,114,114, 97,121,
  10,108,111, 99, 97,108, 32,100,101, 99,111,100,101, 95,115,
  99, 97,110, 67,111,109,109,101,110,116, 10,108,111, 99, 97,
 108, 32,100,101, 99,111,100,101, 95,115, 99, 97,110, 67,111,
 110,115,116, 97,110,116, 10,108,111, 99, 97,108, 32,100,101,
  99,111,100,101, 95,115, 99, 97,110, 78,117,109, 98,101,114,
  10,108,111, 99, 97,108, 32,100,101, 99,111,100,101, 95,115,
  99, 97,110, 79, 98,106,101, 99,116, 10,108,111, 99, 97,108,
  32,100,101, 99,111,100,101, 95,115, 99, 97,110, 83,116,114,
 105,110,103, 10,108,111, 99, 97,108, 32,100,101, 99,111,100,
 101, 95,115, 99, 97,110, 87,104,105,116,101,115,112, 97, 99,
 101, 10,108,111, 99, 97,108, 32,101,110, 99,111,100,101, 83,
 116,114,105,110,103, 10,108,111, 99, 97,108, 32,105,115, 65,
 114,114, 97,121, 10,108,111, 99, 97,108, 32,105,115, 69,110,
  99,111,100, 97, 98,108,101, 10,102,117,110, 99,116,105,111,
 110, 32,106,115,111,110, 46,101,110, 99,111,100,101, 32, 40,
 118, 44, 32,112,108, 97,105,110, 95,111, 98,106,101, 99,116,
  41, 10,105,102, 32,118, 61, 61,110,105,108, 32,116,104,101,
 110, 10,114,101,116,117,114,110, 32, 34,110,117,108,108, 34,
  10,101,110,100, 10,108,111, 99, 97,108, 32,118,116,121,112,
 101, 32, 61, 32,116,121,112,101, 40,118, 41, 10,105,102, 32,
 118,116,121,112,101, 61, 61, 39,115,116,114,105,110,103, 39,
  32,116,104,101,110, 10,114,101,116,117,114,110, 32,112,108,
  97,105,110, 95,111, 98,106,101, 99,116, 32, 97,110,100, 32,
  39, 34, 39, 46, 46,106,115,111,110, 95,112,114,105,118, 97,
 116,101, 46,101,110, 99,111,100,101, 83,116,114,105,110,103,
  40,118, 41, 46, 46, 39, 34, 39, 32,111,114, 32, 39,123, 34,
 118, 97,108,117,101, 34, 58, 34, 39, 46, 46,106,115,111,110,
  95,112,114,105,118, 97,116,101, 46,101,110, 99,111,100,101,
  83,116,114,105,110,103, 40,118, 41, 46, 46, 39, 34,125, 39,
  10,101,110,100, 10,105,102, 32,118,116,121,112,101, 61, 61,
  39, 98,111,111,108,101, 97,110, 39, 32,116,104,101,110, 10,
 114,101,116,117,114,110, 32,112,108, 97,105,110, 95,111, 98,
 106,101, 99,116, 32, 97,110,100, 32,116,111,115,116,114,105,
 110,103, 40,118, 41, 32,111,114, 32, 39,123, 34,118, 97,108,
 117,101, 34, 58, 39, 46, 46,116,111,115,116,114,105,110,103,
  40,118, 41, 46, 46, 39,125, 39, 10,101,110,100, 10,105,102,
  32,118,116,121,112,101, 61, 61, 39,110,117,109, 98,101,114,
  39, 32,116,104,101,110, 10,114,101,116,117,114,110, 32,112,
 108, 97,105,110, 95,111, 98,106,101, 99,116, 32, 97,110,100,
  32,115,116,114,105,110,103, 46,102,111,114,109, 97,116, 40,
  34, 37,102, 34, 44, 32,118, 41, 32,111,114, 32, 39,123, 34,
 118, 97,108,117,101, 34, 58, 39, 46, 46,115,116,114,105,110,
 103, 46,102,111,114,109, 97,116, 40, 34, 37,102, 34, 44, 32,
 118, 41, 46, 46, 39,125, 39, 10,101,110,100, 10,105,102, 32,
 118,116,121,112,101, 32, 61, 61, 32, 39,117,115,101,114,100,
  97,116, 97, 39, 32, 97,110,100, 32,118, 46,116,111, 74, 83,
  79, 78, 32,126, 61, 32,110,105,108, 32,116,104,101,110, 10,
 114,101,116,117,114,110, 32,118, 58,116,111, 74, 83, 79, 78,
  40, 41, 10,101,110,100, 10,105,102, 32,118,116,121,112,101,
  61, 61, 39,116, 97, 98,108,101, 39, 32,116,104,101,110, 10,
 108,111, 99, 97,108, 32,114,118, 97,108, 32, 61, 32,123,125,
  10,108,111, 99, 97,108, 32, 98, 65,114,114, 97,121, 44, 32,
 109, 97,120, 67,111,117,110,116, 32, 61, 32,105,115, 65,114,
 114, 97,121, 40,118, 41, 10,105,102, 32, 98, 65,114,114, 97,
 121, 32,116,104,101,110, 10,102,111,114, 32,105, 32, 61, 32,
  49, 44,109, 97,120, 67,111,117,110,116, 32,100,111, 10,116,
  97, 98,108,101, 46,105,110,115,101,114,116, 40,114,118, 97,
 108, 44, 32,106,115,111,110, 46,101,110, 99,111,100,101, 40,
 118, 91,105, 93, 44, 32,112,108, 97,105,110, 95,111, 98,106,
 101, 99,116, 41, 41, 10,101,110,100, 10,101,108,115,101, 10,
 102,111,114, 32,105, 44,106, 32,105,110, 32,112, 97,105,114,
 115, 40,118, 41, 32,100,111, 10,105,102, 32,105,115, 69,110,
  99,111,100, 97, 98,108,101, 40,105, 41, 32, 97,110,100, 32,
 105,115, 69,110, 99,111,100, 97, 98,108,101, 40,106, 41, 32,
 116,104,101,110, 10,116, 97, 98,108,101, 46,105,110,115,101,
 114,116, 40,114,118, 97,108, 44, 32, 39, 34, 39, 32, 46, 46,
  32,106,115,111,110, 95,112,114,105,118, 97,116,101, 46,101,
 110, 99,111,100,101, 83,116,114,105,110,103, 40,105, 41, 32,
  46, 46, 32, 39, 34, 58, 39, 32, 46, 46, 32,106,115,111,110,
  46,101,110, 99,111,100,101, 40,106, 44, 32,112,108, 97,105,
 110, 95,111, 98,106,101, 99,116, 41, 41, 10,101,110,100, 10,
 101,110,100, 10,101,110,100, 10,105,102, 32, 98, 65,114,114,
  97,121, 32,116,104,101,110, 10,114,101,116,117,114,110, 32,
  39, 91, 39, 32, 46, 46, 32,116, 97, 98,108,101, 46, 99,111,
 110, 99, 97,116, 40,114,118, 97,108, 44, 39, 44, 39, 41, 32,
  46, 46, 39, 93, 39, 10,101,108,115,101, 10,114,101,116,117,
 114,110, 32, 39,123, 39, 32, 46, 46, 32,116, 97, 98,108,101,
  46, 99,111,110, 99, 97,116, 40,114,118, 97,108, 44, 39, 44,
  39, 41, 32, 46, 46, 32, 39,125, 39, 10,101,110,100, 10,101,
 110,100, 10,105,102, 32,118,116,121,112,101, 61, 61, 39,102,
 117,110, 99,116,105,111,110, 39, 32, 97,110,100, 32,118, 61,
  61,110,117,108,108, 32,116,104,101,110, 10,114,101,116,117,
 114,110, 32, 39,110,117,108,108, 39, 10,101,110,100, 10, 97,
 115,115,101,114,116, 40,102, 97,108,115,101, 44, 39,101,110,
  99,111,100,101, 32, 97,116,116,101,109,112,116, 32,116,111,
  32,101,110, 99,111,100,101, 32,117,110,115,117,112,112,111,
 114,116,101,100, 32,116,121,112,101, 32, 39, 32, 46, 46, 32,
 118,116,121,112,101, 32, 46, 46, 32, 39, 58, 39, 32, 46, 46,
  32,116,111,115,116,114,105,110,103, 40,118, 41, 41, 10,101,
 110,100, 10,102,117,110, 99,116,105,111,110, 32,106,115,111,
 110, 46,100,101, 99,111,100,101, 40,115, 44, 32,115,116, 97,
 114,116, 80,111,115, 41, 10,115,116, 97,114,116, 80,111,115,
  32, 61, 32,115,116, 97,114,116, 80,111,115, 32, 97,110,100,
  32,115,116, 97,114,116, 80,111,115, 32,111,114, 32, 49, 10,
 115,116, 97,114,116, 80,111,115, 32, 61, 32,100,101, 99,111,
 100,101, 95,115, 99, 97,110, 87,104,105,116,101,115,112, 97,
  99,101, 40,115, 44,115,116, 97,114,116, 80,111,115, 41, 10,
  97,115,115,101,114,116, 40,115,116, 97,114,116, 80,111,115,
  60, 61,115,116,114,105,110,103, 46,108,101,110, 40,115, 41,
  44, 32, 39, 85,110,116,101,114,109,105,110, 97,116,101,100,
  32, 74, 83, 79, 78, 32,101,110, 99,111,100,101,100, 32,111,
  98,106,101, 99,116, 32,102,111,117,110,100, 32, 97,116, 32,
 112,111,115,105,116,105,111,110, 32,105,110, 32, 91, 39, 32,
  46, 46, 32,115, 32, 46, 46, 32, 39, 93, 39, 41, 10,108,111,
  99, 97,108, 32, 99,117,114, 67,104, 97,114, 32, 61, 32,115,
 116,114,105,110,103, 46,115,117, 98, 40,115, 44,115,116, 97,
 114,116, 80,111,115, 44,115,116, 97,114,116, 80,111,115, 41,
  10,105,102, 32, 99,117,114, 67,104, 97,114, 61, 61, 39,123,
  39, 32,116,104,101,110, 10,114,101,116,117,114,110, 32,100,
 101, 99,111,100,101, 95,115, 99, 97,110, 79, 98,106,101, 99,
 116, 40,115, 44,115,116, 97,114,116, 80,111,115, 41, 10,101,
 110,100, 10,105,102, 32, 99,117,114, 67,104, 97,114, 61, 61,
  39, 91, 39, 32,116,104,101,110, 10,114,101,116,117,114,110,
  32,100,101, 99,111,100,101, 95,115, 99, 97,110, 65,114,114,
  97,121, 40,115, 44,115,116, 97,114,116, 80,111,115, 41, 10,
 101,110,100, 10,105,102, 32,115,116,114,105,110,103, 46,102,
 105,110,100, 40, 34, 43, 45, 48, 49, 50, 51, 52, 53, 54, 55,
  56, 57, 46,101, 34, 44, 32, 99,117,114, 67,104, 97,114, 44,
  32, 49, 44, 32,116,114,117,101, 41, 32,116,104,101,110, 10,
 114,101,116,117,114,110, 32,100,101, 99,111,100,101, 95,115,
  99, 97,110, 78,117,109, 98,101,114, 40,115, 44,115,116, 97,
 114,116, 80,111,115, 41, 10,101,110,100, 10,105,102, 32, 99,
 117,114, 67,104, 97,114, 61, 61, 91, 91, 34, 93, 93, 32,111,
 114, 32, 99,117,114, 67,104, 97,114, 61, 61, 91, 91, 39, 93,
  93, 32,116,104,101,110, 10,114,101,116,117,114,110, 32,100,
 101, 99,111,100,101, 95,115, 99, 97,110, 83,116,114,105,110,
 103, 40,115, 44,115,116, 97,114,116, 80,111,115, 41, 10,101,
 110,100, 10,105,102, 32,115,116,114,105,110,103, 46,115,117,
  98, 40,115, 44,115,116, 97,114,116, 80,111,115, 44,115,116,
  97,114,116, 80,111,115, 43, 49, 41, 61, 61, 39, 47, 42, 39,
  32,116,104,101,110, 10,114,101,116,117,114,110, 32,100,101,
  99,111,100,101, 40,115, 44, 32,100,101, 99,111,100,101, 95,
 115, 99, 97,110, 67,111,109,109,101,110,116, 40,115, 44,115,
 116, 97,114,116, 80,111,115, 41, 41, 10,101,110,100, 10,114,
 101,116,117,114,110, 32,100,101, 99,111,100,101, 95,115, 99,
  97,110, 67,111,110,115,116, 97,110,116, 40,115, 44,115,116,
  97,114,116, 80,111,115, 41, 10,101,110,100, 10,102,117,110,
  99,116,105,111,110, 32,110,117,108,108, 40, 41, 10,114,101,
 116,117,114,110, 32,110,117,108,108, 10,101,110,100, 10,102,
 117,110, 99,116,105,111,110, 32,100,101, 99,111,100,101, 95,
 115, 99, 97,110, 65,114,114, 97,121, 40,115, 44,115,116, 97,
 114,116, 80,111,115, 41, 10,108,111, 99, 97,108, 32, 97,114,
 114, 97,121, 32, 61, 32,123,125, 10,108,111, 99, 97,108, 32,
 115,116,114,105,110,103, 76,101,110, 32, 61, 32,115,116,114,
 105,110,103, 46,108,101,110, 40,115, 41, 10, 97,115,115,101,
 114,116, 40,115,116,114,105,110,103, 46,115,117, 98, 40,115,
  44,115,116, 97,114,116, 80,111,115, 44,115,116, 97,114,116,
  80,111,115, 41, 61, 61, 39, 91, 39, 44, 39,100,101, 99,111,
 100,101, 95,115, 99, 97,110, 65,114,114, 97,121, 32, 99, 97,
 108,108,101,100, 32, 98,117,116, 32, 97,114,114, 97,121, 32,
 100,111,101,115, 32,110,111,116, 32,115,116, 97,114,116, 32,
  97,116, 32,112,111,115,105,116,105,111,110, 32, 39, 32, 46,
  46, 32,115,116, 97,114,116, 80,111,115, 32, 46, 46, 32, 39,
  32,105,110, 32,115,116,114,105,110,103, 58, 92,110, 39, 46,
  46,115, 32, 41, 10,115,116, 97,114,116, 80,111,115, 32, 61,
  32,115,116, 97,114,116, 80,111,115, 32, 43, 32, 49, 10,114,
 101,112,101, 97,116, 10,115,116, 97,114,116, 80,111,115, 32,
  61, 32,100,101, 99,111,100,101, 95,115, 99, 97,110, 87,104,
 105,116,101,115,112, 97, 99,101, 40,115, 44,115,116, 97,114,
 116, 80,111,115, 41, 10, 97,115,115,101,114,116, 40,115,116,
  97,114,116, 80,111,115, 60, 61,115,116,114,105,110,103, 76,
 101,110, 44, 39, 74, 83, 79, 78, 32, 83,116,114,105,110,103,
  32,101,110,100,101,100, 32,117,110,101,120,112,101, 99,116,
 101,100,108,121, 32,115, 99, 97,110,110,105,110,103, 32, 97,
 114,114, 97,121, 46, 39, 41, 10,108,111, 99, 97,108, 32, 99,
 117,114, 67,104, 97,114, 32, 61, 32,115,116,114,105,110,103,
  46,115,117, 98, 40,115, 44,115,116, 97,114,116, 80,111,115,
  44,115,116, 97,114,116, 80,111,115, 41, 10,105,102, 32, 40,
  99,117,114, 67,104, 97,114, 61, 61, 39, 93, 39, 41, 32,116,
 104,101,110, 10,114,101,116,117,114,110, 32, 97,114,114, 97,
 121, 44, 32,115,116, 97,114,116, 80,111,115, 43, 49, 10,101,
 110,100, 10,105,102, 32, 40, 99,117,114, 67,104, 97,114, 61,
  61, 39, 44, 39, 41, 32,116,104,101,110, 10,115,116, 97,114,
 116, 80,111,115, 32, 61, 32,100,101, 99,111,100,101, 95,115,
  99, 97,110, 87,104,105,116,101,115,112, 97, 99,101, 40,115,
  44,115,116, 97,114,116, 80,111,115, 43, 49, 41, 10,101,110,
 100, 10, 97,115,115,101,114,116, 40,115,116, 97,114,116, 80,
 111,115, 60, 61,115,116,114,105,110,103, 76,101,110, 44, 32,
  39, 74, 83, 79, 78, 32, 83,116,114,105,110,103, 32,101,110,
 100,101,100, 32,117,110,101,120,112,101, 99,116,101,100,108,
 121, 32,115, 99, 97,110,110,105,110,103, 32, 97,114,114, 97,
 121, 46, 39, 41, 10,111, 98,106,101, 99,116, 44, 32,115,116,
  97,114,116, 80,111,115, 32, 61, 32,106,115,111,110, 46,100,
 101, 99,111,100,101, 40,115, 44,115,116, 97,114,116, 80,111,
 115, 41, 10,116, 97, 98,108,101, 46,105,110,115,101,114,116,
  40, 97,114,114, 97,121, 44,111, 98,106,101, 99,116, 41, 10,
 117,110,116,105,108, 32,102, 97,108,115,101, 10,101,110,100,
  10,102,117,110, 99,116,105,111,110, 32,100,101, 99,111,100,
 101, 95,115, 99, 97,110, 67,111,109,109,101,110,116, 40,115,
  44, 32,115,116, 97,114,116, 80,111,115, 41, 10, 97,115,115,
 101,114,116, 40, 32,115,116,114,105,110,103, 46,115,117, 98,
  40,115, 44,115,116, 97,114,116, 80,111,115, 44,115,116, 97,
 114,116, 80,111,115, 43, 49, 41, 61, 61, 39, 47, 42, 39, 44,
  32, 34,100,101, 99,111,100,101, 95,115, 99, 97,110, 67,111,
 109,109,101,110,116, 32, 99, 97,108,108,101,100, 32, 98,117,
 116, 32, 99,111,109,109,101,110,116, 32,100,111,101,115, 32,
 110,111,116, 32,115,116, 97,114,116, 32, 97,116, 32,112,111,
 115,105,116,105,111,110, 32, 34, 32, 46, 46, 32,115,116, 97,
 114,116, 80,111,115, 41, 10,108,111, 99, 97,108, 32,101,110,
 100, 80,111,115, 32, 61, 32,115,116,114,105,110,103, 46,102,
 105,110,100, 40,115, 44, 39, 42, 47, 39, 44,115,116, 97,114,
 116, 80,111,115, 43, 50, 41, 10, 97,115,115,101,114,116, 40,
 101,110,100, 80,111,115,126, 61,110,105,108, 44, 32, 34, 85,
 110,116,101,114,109,105,110, 97,116,101,100, 32, 99,111,109,
 109,101,110,116, 32,105,110, 32,115,116,114,105,110,103, 32,
  97,116, 32, 34, 32, 46, 46, 32,115,116, 97,114,116, 80,111,
 115, 41, 10,114,101,116,117,114,110, 32,101,110,100, 80,111,
 115, 43, 50, 10,101,110,100, 10,102,117,110, 99,116,105,111,
 110, 32,100,101, 99,111,100,101, 95,115, 99, 97,110, 67,111,
 110,115,116, 97,110,116, 40,115, 44, 32,115,116, 97,114,116,
  80,111,115, 41, 10,108,111, 99, 97,108, 32, 99,111,110,115,
 116,115, 32, 61, 32,123, 32, 91, 34,116,114,117,101, 34, 93,
  32, 61, 32,116,114,117,101, 44, 32, 91, 34,102, 97,108,115,
 101, 34, 93, 32, 61, 32,102, 97,108,115,101, 44, 32, 91, 34,
 110,117,108,108, 34, 93, 32, 61, 32,110,105,108, 32,125, 10,
 108,111, 99, 97,108, 32, 99,111,110,115,116, 78, 97,109,101,
 115, 32, 61, 32,123, 34,116,114,117,101, 34, 44, 34,102, 97,
 108,115,101, 34, 44, 34,110,117,108,108, 34,125, 10,102,111,
 114, 32,105, 44,107, 32,105,110, 32,112, 97,105,114,115, 40,
  99,111,110,115,116, 78, 97,109,101,115, 41, 32,100,111, 10,
 105,102, 32,115,116,114,105,110,103, 46,115,117, 98, 40,115,
  44,115,116, 97,114,116, 80,111,115, 44, 32,115,116, 97,114,
 116, 80,111,115, 32, 43, 32,115,116,114,105,110,103, 46,108,
 101,110, 40,107, 41, 32, 45, 49, 32, 41, 61, 61,107, 32,116,
 104,101,110, 10,114,101,116,117,114,110, 32, 99,111,110,115,
 116,115, 91,107, 93, 44, 32,115,116, 97,114,116, 80,111,115,
  32, 43, 32,115,116,114,105,110,103, 46,108,101,110, 40,107,
  41, 10,101,110,100, 10,101,110,100, 10, 97,115,115,101,114,
 116, 40,110,105,108, 44, 32, 39, 70, 97,105,108,101,100, 32,
 116,111, 32,115, 99, 97,110, 32, 99,111,110,115,116, 97,110,
 116, 32,102,114,111,109, 32,115,116,114,105,110,103, 32, 39,
  32, 46, 46, 32,115, 32, 46, 46, 32, 39, 32, 97,116, 32,115,
 116, 97,114,116,105,110,103, 32,112,111,115,105,116,105,111,
 110, 32, 39, 32, 46, 46, 32,115,116, 97,114,116, 80,111,115,
  41, 10,101,110,100, 10,102,117,110, 99,116,105,111,110, 32,
 100,101, 99,111,100,101, 95,115, 99, 97,110, 78,117,109, 98,
 101,114, 40,115, 44,115,116, 97,114,116, 80,111,115, 41, 10,
 108,111, 99, 97,108, 32,101,110,100, 80,111,115, 32, 61, 32,
 115,116, 97,114,116, 80,111,115, 43, 49, 10,108,111, 99, 97,
 108, 32,115,116,114,105,110,103, 76,101,110, 32, 61, 32,115,
 116,114,105,110,103, 46,108,101,110, 40,115, 41, 10,108,111,
  99, 97,108, 32, 97, 99, 99,101,112,116, 97, 98,108,101, 67,
 104, 97,114,115, 32, 61, 32, 34, 43, 45, 48, 49, 50, 51, 52,
  53, 54, 55, 56, 57, 46,101, 34, 10,119,104,105,108,101, 32,
  40,115,116,114,105,110,103, 46,102,105,110,100, 40, 97, 99,
  99,101,112,116, 97, 98,108,101, 67,104, 97,114,115, 44, 32,
 115,116,114,105,110,103, 46,115,117, 98, 40,115, 44,101,110,
 100, 80,111,115, 44,101,110,100, 80,111,115, 41, 44, 32, 49,
  44, 32,116,114,117,101, 41, 10, 97,110,100, 32,101,110,100,
  80,111,115, 60, 61,115,116,114,105,110,103, 76,101,110, 10,
  41, 32,100,111, 10,101,110,100, 80,111,115, 32, 61, 32,101,
 110,100, 80,111,115, 32, 43, 32, 49, 10,101,110,100, 10,108,
 111, 99, 97,108, 32,115,116,114,105,110,103, 86, 97,108,117,
 101, 32, 61, 32, 39,114,101,116,117,114,110, 32, 39, 32, 46,
  46, 32,115,116,114,105,110,103, 46,115,117, 98, 40,115, 44,
 115,116, 97,114,116, 80,111,115, 44, 32,101,110,100, 80,111,
 115, 45, 49, 41, 10,108,111, 99, 97,108, 32,115,116,114,105,
 110,103, 69,118, 97,108, 32, 61, 32,108,111, 97,100,115,116,
 114,105,110,103, 40,115,116,114,105,110,103, 86, 97,108,117,
 101, 41, 10, 97,115,115,101,114,116, 40,115,116,114,105,110,
 103, 69,118, 97,108, 44, 32, 39, 70, 97,105,108,101,100, 32,
 116,111, 32,115, 99, 97,110, 32,110,117,109, 98,101,114, 32,
  91, 32, 39, 32, 46, 46, 32,115,116,114,105,110,103, 86, 97,
 108,117,101, 32, 46, 46, 32, 39, 93, 32,105,110, 32, 74, 83,
  79, 78, 32,115,116,114,105,110,103, 32, 97,116, 32,112,111,
 115,105,116,105,111,110, 32, 39, 32, 46, 46, 32,115,116, 97,
 114,116, 80,111,115, 32, 46, 46, 32, 39, 32, 58, 32, 39, 32,
  46, 46, 32,101,110,100, 80,111,115, 41, 10,114,101,116,117,
 114,110, 32,115,116,114,105,110,103, 69,118, 97,108, 40, 41,
  44, 32,101,110,100, 80,111,115, 10,101,110,100, 10,102,117,
 110, 99,116,105,111,110, 32,100,101, 99,111,100,101, 95,115,
  99, 97,110, 79, 98,106,101, 99,116, 40,115, 44,115,116, 97,
 114,116, 80,111,115, 41, 10,108,111, 99, 97,108, 32,111, 98,
 106,101, 99,116, 32, 61, 32,123,125, 10,108,111, 99, 97,108,
  32,115,116,114,105,110,103, 76,101,110, 32, 61, 32,115,116,
 114,105,110,103, 46,108,101,110, 40,115, 41, 10,108,111, 99,
  97,108, 32,107,101,121, 44, 32,118, 97,108,117,101, 10, 97,
 115,115,101,114,116, 40,115,116,114,105,110,103, 46,115,117,
  98, 40,115, 44,115,116, 97,114,116, 80,111,115, 44,115,116,
  97,114,116, 80,111,115, 41, 61, 61, 39,123, 39, 44, 39,100,
 101, 99,111,100,101, 95,115, 99, 97,110, 79, 98,106,101, 99,
 116, 32, 99, 97,108,108,101,100, 32, 98,117,116, 32,111, 98,
 106,101, 99,116, 32,100,111,101,115, 32,110,111,116, 32,115,
 116, 97,114,116, 32, 97,116, 32,112,111,115,105,116,105,111,
 110, 32, 39, 32, 46, 46, 32,115,116, 97,114,116, 80,111,115,
  32, 46, 46, 32, 39, 32,105,110, 32,115,116,114,105,110,103,
  58, 92,110, 39, 32, 46, 46, 32,115, 41, 10,115,116, 97,114,
 116, 80,111,115, 32, 61, 32,115,116, 97,114,116, 80,111,115,
  32, 43, 32, 49, 10,114,101,112,101, 97,116, 10,115,116, 97,
 114,116, 80,111,115, 32, 61, 32,100,101, 99,111,100,101, 95,
 115, 99, 97,110, 87,104,105,116,101,115,112, 97, 99,101, 40,
 115, 44,115,116, 97,114,116, 80,111,115, 41, 10, 97,115,115,
 101,114,116, 40,115,116, 97,114,116, 80,111,115, 60, 61,115,
 116,114,105,110,103, 76,101,110, 44, 32, 39, 74, 83, 79, 78,
  32,115,116,114,105,110,103, 32,101,110,100,101,100, 32,117,
 110,101,120,112,101, 99,116,101,100,108,121, 32,119,104,105,
 108,101, 32,115, 99, 97,110,110,105,110,103, 32,111, 98,106,
 101, 99,116, 46, 39, 41, 10,108,111, 99, 97,108, 32, 99,117,
 114, 67,104, 97,114, 32, 61, 32,115,116,114,105,110,103, 46,
 115,117, 98, 40,115, 44,115,116, 97,114,116, 80,111,115, 44,
 115,116, 97,114,116, 80,111,115, 41, 10,105,102, 32, 40, 99,
 117,114, 67,104, 97,114, 61, 61, 39,125, 39, 41, 32,116,104,
 101,110, 10,114,101,116,117,114,110, 32,111, 98,106,101, 99,
 116, 44,115,116, 97,114,116, 80,111,115, 43, 49, 10,101,110,
 100, 10,105,102, 32, 40, 99,117,114, 67,104, 97,114, 61, 61,
  39, 44, 39, 41, 32,116,104,101,110, 10,115,116, 97,114,116,
  80,111,115, 32, 61, 32,100,101, 99,111,100,101, 95,115, 99,
  97,110, 87,104,105,116,101,115,112, 97, 99,101, 40,115, 44,
 115,116, 97,114,116, 80,111,115, 43, 49, 41, 10,101,110,100,
  10, 97,115,115,101,114,116, 40,115,116, 97,114,116, 80,111,
 115, 60, 61,115,116,114,105,110,103, 76,101,110, 44, 32, 39,
  74, 83, 79, 78, 32,115,116,114,105,110,103, 32,101,110,100,
 101,100, 32,117,110,101,120,112,101, 99,116,101,100,108,121,
  32,115, 99, 97,110,110,105,110,103, 32,111, 98,106,101, 99,
 116, 46, 39, 41, 10,107,101,121, 44, 32,115,116, 97,114,116,
  80,111,115, 32, 61, 32,106,115,111,110, 46,100,101, 99,111,
 100,101, 40,115, 44,115,116, 97,114,116, 80,111,115, 41, 10,
  97,115,115,101,114,116, 40,115,116, 97,114,116, 80,111,115,
  60, 61,115,116,114,105,110,103, 76,101,110, 44, 32, 39, 74,
  83, 79, 78, 32,115,116,114,105,110,103, 32,101,110,100,101,
 100, 32,117,110,101,120,112,101, 99,116,101,100,108,121, 32,
 115,101, 97,114, 99,104,105,110,103, 32,102,111,114, 32,118,
  97,108,117,101, 32,111,102, 32,107,101,121, 32, 39, 32, 46,
  46, 32,107,101,121, 41, 10,115,116, 97,114,116, 80,111,115,
  32, 61, 32,100,101, 99,111,100,101, 95,115, 99, 97,110, 87,
 104,105,116,101,115,112, 97, 99,101, 40,115, 44,115,116, 97,
 114,116, 80,111,115, 41, 10, 97,115,115,101,114,116, 40,115,
 116, 97,114,116, 80,111,115, 60, 61,115,116,114,105,110,103,
  76,101,110, 44, 32, 39, 74, 83, 79, 78, 32,115,116,114,105,
 110,103, 32,101,110,100,101,100, 32,117,110,101,120,112,101,
  99,116,101,100,108,121, 32,115,101, 97,114, 99,104,105,110,
 103, 32,102,111,114, 32,118, 97,108,117,101, 32,111,102, 32,
 107,101,121, 32, 39, 32, 46, 46, 32,107,101,121, 41, 10, 97,
 115,115,101,114,116, 40,115,116,114,105,110,103, 46,115,117,
  98, 40,115, 44,115,116, 97,114,116, 80,111,115, 44,115,116,
  97,114,116, 80,111,115, 41, 61, 61, 39, 58, 39, 44, 39, 74,
  83, 79, 78, 32,111, 98,106,101, 99,116, 32,107,101,121, 45,
 118, 97,108,117,101, 32, 97,115,115,105,103,110,109,101,110,
 116, 32,109, 97,108, 45,102,111,114,109,101,100, 32, 97,116,
  32, 39, 32, 46, 46, 32,115,116, 97,114,116, 80,111,115, 41,
  10,115,116, 97,114,116, 80,111,115, 32, 61, 32,100,101, 99,
 111,100,101, 95,115, 99, 97,110, 87,104,105,116,101,115,112,
  97, 99,101, 40,115, 44,115,116, 97,114,116, 80,111,115, 43,
  49, 41, 10, 97,115,115,101,114,116, 40,115,116, 97,114,116,
  80,111,115, 60, 61,115,116,114,105,110,103, 76,101,110, 44,
  32, 39, 74, 83, 79, 78, 32,115,116,114,105,110,103, 32,101,
 110,100,101,100, 32,117,110,101,120,112,101, 99,116,101,100,
 108,121, 32,115,101, 97,114, 99,104,105,110,103, 32,102,111,
 114, 32,118, 97,108,117,101, 32,111,102, 32,107,101,121, 32,
  39, 32, 46, 46, 32,107,101,121, 41, 10,118, 97,108,117,101,
  44, 32,115,116, 97,114,116, 80,111,115, 32, 61, 32,106,115,
 111,110, 46,100,101, 99,111,100,101, 40,115, 44,115,116, 97,
 114,116, 80,111,115, 41, 10,111, 98,106,101, 99,116, 91,107,
 101,121, 93, 61,118, 97,108,117,101, 10,117,110,116,105,108,
  32,102, 97,108,115,101, 10,101,110,100, 10,108,111, 99, 97,
 108, 32,101,115, 99, 97,112,101, 83,101,113,117,101,110, 99,
 101,115, 32, 61, 32,123, 10, 91, 34, 92, 92,116, 34, 93, 32,
  61, 32, 34, 92,116, 34, 44, 10, 91, 34, 92, 92,102, 34, 93,
  32, 61, 32, 34, 92,102, 34, 44, 10, 91, 34, 92, 92,114, 34,
  93, 32, 61, 32, 34, 92,114, 34, 44, 10, 91, 34, 92, 92,110,
  34, 93, 32, 61, 32, 34, 92,110, 34, 44, 10, 91, 34, 92, 92,
  98, 34, 93, 32, 61, 32, 34, 92, 98, 34, 10,125, 10,115,101,
 116,109,101,116, 97,116, 97, 98,108,101, 40,101,115, 99, 97,
 112,101, 83,101,113,117,101,110, 99,101,115, 44, 32,123, 95,
  95,105,110,100,101,120, 32, 61, 32,102,117,110, 99,116,105,
 111,110, 40,116, 44,107, 41, 10,114,101,116,117,114,110, 32,
 115,116,114,105,110,103, 46,115,117, 98, 40,107, 44, 50, 41,
  10,101,110,100,125, 41, 10,102,117,110, 99,116,105,111,110,
  32,100,101, 99,111,100,101, 95,115, 99, 97,110, 83,116,114,
 105,110,103, 40,115, 44,115,116, 97,114,116, 80,111,115, 41,
  10, 97,115,115,101,114,116, 40,115,116, 97,114,116, 80,111,
 115, 44, 32, 39,100,101, 99,111,100,101, 95,115, 99, 97,110,
  83,116,114,105,110,103, 40, 46, 46, 41, 32, 99, 97,108,108,
 101,100, 32,119,105,116,104,111,117,116, 32,115,116, 97,114,
 116, 32,112,111,115,105,116,105,111,110, 39, 41, 10,108,111,
  99, 97,108, 32,115,116, 97,114,116, 67,104, 97,114, 32, 61,
  32,115,116,114,105,110,103, 46,115,117, 98, 40,115, 44,115,
 116, 97,114,116, 80,111,115, 44,115,116, 97,114,116, 80,111,
 115, 41, 10, 97,115,115,101,114,116, 40,115,116, 97,114,116,
  67,104, 97,114, 32, 61, 61, 32, 91, 91, 34, 93, 93, 32,111,
 114, 32,115,116, 97,114,116, 67,104, 97,114, 32, 61, 61, 32,
  91, 91, 39, 93, 93, 44, 39,100,101, 99,111,100,101, 95,115,
  99, 97,110, 83,116,114,105,110,103, 32, 99, 97,108,108,101,
 100, 32,102,111,114, 32, 97, 32,110,111,110, 45,115,116,114,
 105,110,103, 39, 41, 10,108,111, 99, 97,108, 32,116, 32, 61,
  32,123,125, 10,108,111, 99, 97,108, 32,105, 44,106, 32, 61,
  32,115,116, 97,114,116, 80,111,115, 44,115,116, 97,114,116,
  80,111,115, 10,119,104,105,108,101, 32,115,116,114,105,110,
 103, 46,102,105,110,100, 40,115, 44, 32,115,116, 97,114,116,
  67,104, 97,114, 44, 32,106, 43, 49, 41, 32,126, 61, 32,106,
  43, 49, 32,100,111, 10,108,111, 99, 97,108, 32,111,108,100,
 106, 32, 61, 32,106, 10,105, 44,106, 32, 61, 32,115,116,114,
 105,110,103, 46,102,105,110,100, 40,115, 44, 32, 34, 92, 92,
  46, 34, 44, 32,106, 43, 49, 41, 10,108,111, 99, 97,108, 32,
 120, 44,121, 32, 61, 32,115,116,114,105,110,103, 46,102,105,
 110,100, 40,115, 44, 32,115,116, 97,114,116, 67,104, 97,114,
  44, 32,111,108,100,106, 43, 49, 41, 10,105,102, 32,110,111,
 116, 32,105, 32,111,114, 32,120, 32, 60, 32,105, 32,116,104,
 101,110, 10,105, 44,106, 32, 61, 32,120, 44,121, 45, 49, 10,
 101,110,100, 10,116, 97, 98,108,101, 46,105,110,115,101,114,
 116, 40,116, 44, 32,115,116,114,105,110,103, 46,115,117, 98,
  40,115, 44, 32,111,108,100,106, 43, 49, 44, 32,105, 45, 49,
  41, 41, 10,105,102, 32,115,116,114,105,110,103, 46,115,117,
  98, 40,115, 44, 32,105, 44, 32,106, 41, 32, 61, 61, 32, 34,
  92, 92,117, 34, 32,116,104,101,110, 10,108,111, 99, 97,108,
  32, 97, 32, 61, 32,115,116,114,105,110,103, 46,115,117, 98,
  40,115, 44,106, 43, 49, 44,106, 43, 52, 41, 10,106, 32, 61,
  32,106, 32, 43, 32, 52, 10,108,111, 99, 97,108, 32,110, 32,
  61, 32,116,111,110,117,109, 98,101,114, 40, 97, 44, 32, 49,
  54, 41, 10, 97,115,115,101,114,116, 40,110, 44, 32, 34, 83,
 116,114,105,110,103, 32,100,101, 99,111,100,105,110,103, 32,
 102, 97,105,108,101,100, 58, 32, 98, 97,100, 32, 85,110,105,
  99,111,100,101, 32,101,115, 99, 97,112,101, 32, 34, 32, 46,
  46, 32, 97, 32, 46, 46, 32, 34, 32, 97,116, 32,112,111,115,
 105,116,105,111,110, 32, 34, 32, 46, 46, 32,105, 32, 46, 46,
  32, 34, 32, 58, 32, 34, 32, 46, 46, 32,106, 41, 10,108,111,
  99, 97,108, 32,120, 10,105,102, 32,110, 32, 60, 32, 48,120,
  56, 48, 32,116,104,101,110, 10,120, 32, 61, 32,115,116,114,
 105,110,103, 46, 99,104, 97,114, 40,110, 32, 37, 32, 48,120,
  56, 48, 41, 10,101,108,115,101,105,102, 32,110, 32, 60, 32,
  48,120, 56, 48, 48, 32,116,104,101,110, 10,120, 32, 61, 32,
 115,116,114,105,110,103, 46, 99,104, 97,114, 40, 48,120, 67,
  48, 32, 43, 32, 40,109, 97,116,104, 46,102,108,111,111,114,
  40,110, 47, 54, 52, 41, 32, 37, 32, 48,120, 50, 48, 41, 44,
  32, 48,120, 56, 48, 32, 43, 32, 40,110, 32, 37, 32, 48,120,
  52, 48, 41, 41, 10,101,108,115,101, 10,120, 32, 61, 32,115,
 116,114,105,110,103, 46, 99,104, 97,114, 40, 48,120, 69, 48,
  32, 43, 32, 40,109, 97,116,104, 46,102,108,111,111,114, 40,
 110, 47, 52, 48, 57, 54, 41, 32, 37, 32, 48,120, 49, 48, 41,
  44, 32, 48,120, 56, 48, 32, 43, 32, 40,109, 97,116,104, 46,
 102,108,111,111,114, 40,110, 47, 54, 52, 41, 32, 37, 32, 48,
 120, 52, 48, 41, 44, 32, 48,120, 56, 48, 32, 43, 32, 40,110,
  32, 37, 32, 48,120, 52, 48, 41, 41, 10,101,110,100, 10,116,
  97, 98,108,101, 46,105,110,115,101,114,116, 40,116, 44, 32,
 120, 41, 10,101,108,115,101, 10,116, 97, 98,108,101, 46,105,
 110,115,101,114,116, 40,116, 44, 32,101,115, 99, 97,112,101,
  83,101,113,117,101,110, 99,101,115, 91,115,116,114,105,110,
 103, 46,115,117, 98, 40,115, 44, 32,105, 44, 32,106, 41, 93,
  41, 10,101,110,100, 10,101,110,100, 10,116, 97, 98,108,101,
  46,105,110,115,101,114,116, 40,116, 44,115,116,114,105,110,
 103, 46,115,117, 98, 40,106, 44, 32,106, 43, 49, 41, 41, 10,
  97,115,115,101,114,116, 40,115,116,114,105,110,103, 46,102,
 105,110,100, 40,115, 44, 32,115,116, 97,114,116, 67,104, 97,
 114, 44, 32,106, 43, 49, 41, 44, 32, 34, 83,116,114,105,110,
 103, 32,100,101, 99,111,100,105,110,103, 32,102, 97,105,108,
 101,100, 58, 32,109,105,115,115,105,110,103, 32, 99,108,111,
 115,105,110,103, 32, 34, 32, 46, 46, 32,115,116, 97,114,116,
  67,104, 97,114, 32, 46, 46, 32, 34, 32, 97,116, 32,112,111,
 115,105,116,105,111,110, 32, 34, 32, 46, 46, 32,106, 32, 46,
  46, 32, 34, 40,102,111,114, 32,115,116,114,105,110,103, 32,
  97,116, 32,112,111,115,105,116,105,111,110, 32, 34, 32, 46,
  46, 32,115,116, 97,114,116, 80,111,115, 32, 46, 46, 32, 34,
  41, 34, 41, 10,114,101,116,117,114,110, 32,116, 97, 98,108,
 101, 46, 99,111,110, 99, 97,116, 40,116, 44, 34, 34, 41, 44,
  32,106, 43, 50, 10,101,110,100, 10,102,117,110, 99,116,105,
 111,110, 32,100,101, 99,111,100,101, 95,115, 99, 97,110, 87,
 104,105,116,101,115,112, 97, 99,101, 40,115, 44,115,116, 97,
 114,116, 80,111,115, 41, 10,108,111, 99, 97,108, 32,119,104,
 105,116,101,115,112, 97, 99,101, 61, 34, 32, 92,110, 92,114,
  92,116, 34, 10,108,111, 99, 97,108, 32,115,116,114,105,110,
 103, 76,101,110, 32, 61, 32,115,116,114,105,110,103, 46,108,
 101,110, 40,115, 41, 10,119,104,105,108,101, 32, 40, 32,115,
 116,114,105,110,103, 46,102,105,110,100, 40,119,104,105,116,
 101,115,112, 97, 99,101, 44, 32,115,116,114,105,110,103, 46,
 115,117, 98, 40,115, 44,115,116, 97,114,116, 80,111,115, 44,
 115,116, 97,114,116, 80,111,115, 41, 44, 32, 49, 44, 32,116,
 114,117,101, 41, 32, 97,110,100, 32,115,116, 97,114,116, 80,
 111,115, 32, 60, 61, 32,115,116,114,105,110,103, 76,101,110,
  41, 32,100,111, 10,115,116, 97,114,116, 80,111,115, 32, 61,
  32,115,116, 97,114,116, 80,111,115, 32, 43, 32, 49, 10,101,
 110,100, 10,114,101,116,117,114,110, 32,115,116, 97,114,116,
  80,111,115, 10,101,110,100, 10,108,111, 99, 97,108, 32,101,
 115, 99, 97,112,101, 76,105,115,116, 32, 61, 32,123, 10, 91,
  39, 34, 39, 93, 32, 61, 32, 39, 92, 92, 34, 39, 44, 10, 91,
  39, 92, 92, 39, 93, 32, 61, 32, 39, 92, 92, 92, 92, 39, 44,
  10, 91, 39, 47, 39, 93, 32, 61, 32, 39, 92, 92, 47, 39, 44,
  10, 91, 39, 92, 98, 39, 93, 32, 61, 32, 39, 92, 92, 98, 39,
  44, 10, 91, 39, 92,102, 39, 93, 32, 61, 32, 39, 92, 92,102,
  39, 44, 10, 91, 39, 92,110, 39, 93, 32, 61, 32, 39, 92, 92,
 110, 39, 44, 10, 91, 39, 92,114, 39, 93, 32, 61, 32, 39, 92,
  92,114, 39, 44, 10, 91, 39, 92,116, 39, 93, 32, 61, 32, 39,
  92, 92,116, 39, 10,125, 10,102,117,110, 99,116,105,111,110,
  32,106,115,111,110, 95,112,114,105,118, 97,116,101, 46,101,
 110, 99,111,100,101, 83,116,114,105,110,103, 40,115, 41, 10,
 108,111, 99, 97,108, 32,115, 32, 61, 32,116,111,115,116,114,
 105,110,103, 40,115, 41, 10,114,101,116,117,114,110, 32,115,
  58,103,115,117, 98, 40, 34, 46, 34, 44, 32,102,117,110, 99,
 116,105,111,110, 40, 99, 41, 32,114,101,116,117,114,110, 32,
 101,115, 99, 97,112,101, 76,105,115,116, 91, 99, 93, 32,101,
 110,100, 41, 10,101,110,100, 10,102,117,110, 99,116,105,111,
 110, 32,105,115, 65,114,114, 97,121, 40,116, 41, 10,108,111,
  99, 97,108, 32,109, 97,120, 73,110,100,101,120, 32, 61, 32,
  48, 10,102,111,114, 32,107, 44,118, 32,105,110, 32,112, 97,
 105,114,115, 40,116, 41, 32,100,111, 10,105,102, 32, 40,116,
 121,112,101, 40,107, 41, 61, 61, 39,110,117,109, 98,101,114,
  39, 32, 97,110,100, 32,109, 97,116,104, 46,102,108,111,111,
 114, 40,107, 41, 61, 61,107, 32, 97,110,100, 32, 49, 60, 61,
 107, 41, 32,116,104,101,110, 10,105,102, 32, 40,110,111,116,
  32,105,115, 69,110, 99,111,100, 97, 98,108,101, 40,118, 41,
  41, 32,116,104,101,110, 32,114,101,116,117,114,110, 32,102,
  97,108,115,101, 32,101,110,100, 10,109, 97,120, 73,110,100,
 101,120, 32, 61, 32,109, 97,116,104, 46,109, 97,120, 40,109,
  97,120, 73,110,100,101,120, 44,107, 41, 10,101,108,115,101,
  10,105,102, 32, 40,107, 61, 61, 39,110, 39, 41, 32,116,104,
 101,110, 10,105,102, 32,118, 32,126, 61, 32,116, 97, 98,108,
 101, 46,103,101,116,110, 40,116, 41, 32,116,104,101,110, 32,
 114,101,116,117,114,110, 32,102, 97,108,115,101, 32,101,110,
 100, 10,101,108,115,101, 10,105,102, 32,105,115, 69,110, 99,
 111,100, 97, 98,108,101, 40,118, 41, 32,116,104,101,110, 32,
 114,101,116,117,114,110, 32,102, 97,108,115,101, 32,101,110,
 100, 10,101,110,100, 10,101,110,100, 10,101,110,100, 10,114,
 101,116,117,114,110, 32,116,114,117,101, 44, 32,109, 97,120,
  73,110,100,101,120, 10,101,110,100, 10,102,117,110, 99,116,
 105,111,110, 32,105,115, 69,110, 99,111,100, 97, 98,108,101,
  40,111, 41, 10,108,111, 99, 97,108, 32,116, 32, 61, 32,116,
 121,112,101, 40,111, 41, 10,114,101,116,117,114,110, 32, 40,
 116, 61, 61, 39,115,116,114,105,110,103, 39, 32,111,114, 32,
 116, 61, 61, 39, 98,111,111,108,101, 97,110, 39, 32,111,114,
  32,116, 61, 61, 39,110,117,109, 98,101,114, 39, 32,111,114,
  32,116, 61, 61, 39,110,105,108, 39, 32,111,114, 32,116, 61,
  61, 39,116, 97, 98,108,101, 39, 32,111,114, 32,116, 61, 61,
  39,117,115,101,114,100, 97,116, 97, 39, 41, 32,111,114, 32,
  40,116, 61, 61, 39,102,117,110, 99,116,105,111,110, 39, 32,
  97,110,100, 32,111, 61, 61,110,117,108,108, 41, 10,101,110,
 100, 10,102,117,110, 99,116,105,111,110, 32,106,115,111,110,
  46,101,120,101, 99,117,116,101, 40,115,116, 97,116,101,109,
 101,110,116, 41, 10,108,111, 99, 97,108, 32,114,101,116,117,
 114,110,101,100, 95,111, 98,106,101, 99,116, 32, 61, 32,108,
 111, 97,100,115,116,114,105,110,103, 40, 34,114,101,116,117,
 114,110, 32, 40, 34, 46, 46,115,116, 97,116,101,109,101,110,
 116, 46, 46, 34, 41, 34, 41, 40, 41, 10,114,101,116,117,114,
 110, 32,106,115,111,110, 46,101,110, 99,111,100,101, 40,114,
 101,116,117,114,110,101,100, 95,111, 98,106,101, 99,116, 41,
  10,101,110,100, 10,119,101, 98, 32, 61, 32,123,125, 10,102,
 117,110, 99,116,105,111,110, 32,119,101, 98, 58,101,115, 99,
  97,112,101, 32, 40,115, 41, 10,115, 32, 61, 32,115,116,114,
 105,110,103, 46,103,115,117, 98, 40,115, 44, 32, 34, 40, 91,
  38, 61, 43, 37, 99, 93, 41, 34, 44, 32,102,117,110, 99,116,
 105,111,110, 32, 40, 99, 41, 10,114,101,116,117,114,110, 32,
 115,116,114,105,110,103, 46,102,111,114,109, 97,116, 40, 34,
  37, 37, 37, 48, 50, 88, 34, 44, 32,115,116,114,105,110,103,
  46, 98,121,116,101, 40, 99, 41, 41, 10,101,110,100, 41, 10,
 115, 32, 61, 32,115,116,114,105,110,103, 46,103,115,117, 98,
  40,115, 44, 32, 34, 32, 34, 44, 32, 34, 43, 34, 41, 10,114,
 101,116,117,114,110, 32,115, 10,101,110,100, 10,102,117,110,
  99,116,105,111,110, 32,119,101, 98, 58,117,110,101,115, 99,
  97,112,101, 32, 40,115, 41, 10,115, 32, 61, 32,115,116,114,
 105,110,103, 46,103,115,117, 98, 40,115, 44, 32, 34, 43, 34,
  44, 32, 34, 32, 34, 41, 10,115, 32, 61, 32,115,116,114,105,
 110,103, 46,103,115,117, 98, 40,115, 44, 32, 34, 37, 37, 40,
  37,120, 37,120, 41, 34, 44, 32,102,117,110, 99,116,105,111,
 110, 32, 40,104, 41, 10,114,101,116,117,114,110, 32,115,116,
 114,105,110,103, 46, 99,104, 97,114, 40,116,111,110,117,109,
  98,101,114, 40,104, 44, 32, 49, 54, 41, 41, 10,101,110,100,
  41, 10,114,101,116,117,114,110, 32,115, 10,101,110,100,32
 };
 if (luaL_loadbuffer(tolua_S,(char*)B,sizeof(B),"tolua: embedded Lua code") == LUA_OK)
 lua_pcall(tolua_S,0,LUA_MULTRET,0);
 } /* end of embedded lua code */

 tolua_endmodule(tolua_S);
 return 1;
}
/* Open tolua function */
TOLUA_API int tolua_Aztec_Lua_Bind_open (lua_State* tolua_S)
{
 lua_pushcfunction(tolua_S, luaopen_Aztec_Lua_Bind);
 lua_pushstring(tolua_S, "Aztec_Lua_Bind");
 lua_call(tolua_S, 1, 0);
 return 1;
}
