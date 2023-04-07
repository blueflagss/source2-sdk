#ifndef CS2_PROJECT_COLLISION_PROPERTY_HPP
#define CS2_PROJECT_COLLISION_PROPERTY_HPP

class c_collision_property {
public:
    SCHEMA_VAR( math::vec3_t, mins, "CCollisionProperty", "m_vecMins" )
    SCHEMA_VAR( math::vec3_t, maxs, "CCollisionProperty", "m_vecMaxs" )
};

#endif//CS2_PROJECT_COLLISION_PROPERTY_HPP
