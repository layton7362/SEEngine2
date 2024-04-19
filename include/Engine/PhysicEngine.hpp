#include <Interface.hpp>

class PhysicWorld: public IDisposable
{
public:
    PhysicWorld();
    virtual ~PhysicWorld();
    virtual void dispose() override;
};
