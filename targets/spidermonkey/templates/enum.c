
#set fields = $current_class.fields

template<>
bool SEVALUE_TO_NATIVE(const se::Value &from, ${current_class.namespaced_class_name} *to, se::Object *ctx)
{
    typedef typename std::underlying_type_t<${current_class.namespaced_class_name}>  under_type;
    under_type tmp;
    if(SEVALUE_TO_NATIVE(from, &tmp, ctx)) { *to = static_cast<${current_class.namespaced_class_name}>(tmp); return true;}
    return false;
}

int js_register_${generator.prefix}_${current_class.class_name}(se::Object* obj)
{
    auto enum_kls = se::Object::createPlainObject();
    #for m in fields
    enum_kls->setProperty("${m['name']}", se::Value(${m['value']}));
    #end for
    obj->setProperty("${current_class.target_class_name}", se::Value(enum_kls));

    se::ScriptEngine::getInstance()->clearException();
    return true;
}
