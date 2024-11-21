#include <Types.hpp>
#include <Core/Resource.hpp>
#include <Core/Log.hpp>
#include <Graphic/Mesh.hpp>
#include <Mesh/Box3D.hpp>
#include <Mesh/Box2D.hpp>
#include <Test.hpp>
#include <Utils.hpp>

bool procedure_ressource(Res<Mesh> res, int checkNumber)
{
    RET_IF_CMP_FAIL(res.get()->getCounter(), checkNumber)
    return true;
}

bool test_Resource_Create()
{
    Res<Mesh> test;
    test.name = "Test";
    Mesh *mesh = test.get();
    RET_IF_CMP_FAIL(mesh, nullptr)

    test = Res<Mesh>::create();
    RET_IF_CMP_FAIL(test.get()->getCounter(), 1)

    mesh = test.get();
    unsigned int& counter = *(unsigned int*)(((char*)(mesh)) + 0x0000000c); 
    RET_IF_NOT_CMP_FAIL(mesh, nullptr)
    test = Res<Mesh>::create();
    RET_IF_NOT_CMP_FAIL(mesh, nullptr)
    {
        Res<Mesh> test2 = test;
        RET_IF_CMP_FAIL(test2.get(), test.get())
        RET_IF_CMP_FAIL(test2.get()->getCounter(), 2)
    }
    RET_IF_CMP_FAIL(test.get()->getCounter(), 1)
    procedure_ressource(test, 2);
    RET_IF_CMP_FAIL(test.get()->getCounter(), 1)
    Res<Box3D> meshBox = Res<Box3D>::create<Box3D>();
    mesh = meshBox.get();
    RET_IF_NOT_CMP_FAIL(mesh, nullptr)
    meshBox = Res<Box3D>::create<Box3D>();
    RET_IF_NOT_CMP_FAIL(mesh, nullptr)

    Res<Mesh> resMesh = Res<Mesh>::create();
    RET_IF_NOT_CMP_FAIL(resMesh.get(), nullptr)

    Res<Mesh> resMeshBox3D = Res<Mesh>::create<Box3D>();
    RET_IF_NOT_CMP_FAIL(resMeshBox3D.get(), nullptr)
    Box3D *subtype = resMeshBox3D.toSubtype<Box3D>();
    RET_IF_NOT_CMP_FAIL(subtype, nullptr)
    RET_IF_CMP_FAIL(resMeshBox3D.as<Box2D>(), nullptr)
    RET_IF_NOT_CMP_FAIL(resMeshBox3D.as<Box3D>(), nullptr)
    return true;
}

int main_Resource(const char *type)
{
    Log::info("====================");
    Log::info(type);
    Log::info("====================");
    assert(test_Resource_Create());

    Log::info(type);
    Log::info("Test ends successful");
    return 0;
}