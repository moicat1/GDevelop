#ifndef GDCORE_PLATFORMEXTENSION_INL
#define GDCORE_PLATFORMEXTENSION_INL

namespace gd
{

template<class T>
gd::ObjectMetadata & PlatformExtension::AddObject(const gd::String & name,
    const gd::String & fullname, const gd::String & description,
    const gd::String & icon24x24)
{
    gd::String nameWithNamespace = GetNameSpace().empty() ? name : GetNameSpace()+name;
    objectsInfos[nameWithNamespace] = ObjectMetadata(
        GetNameSpace(),
        nameWithNamespace,
        fullname,
        informations,
        icon24x24,
        [](gd::String name) -> gd::Object* { return new T(name); }
    );

    return objectsInfos[nameWithNamespace];
}

}

#endif
