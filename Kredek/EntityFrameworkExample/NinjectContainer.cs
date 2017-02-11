using Example.Model;
using Example.Repository;
using Example.Repository.Query;
using Example.Repository.Query.Interfaces;
using Ninject;
using Ninject.Modules;

namespace Example
{
    /// <summary>
    /// Kontener IoC służący do rejestrowania interfejsów wraz z obiektami.
    /// 
    /// </summary>
    public class NinjectContainer : NinjectModule
    {
        private readonly IKernel _kernel;

        public NinjectContainer(IKernel kernel)
        {
            _kernel = kernel;
        }

        public override void Load()
        {
            // InSingletonScope() oznacza, że w całej aplikacji będzie dokładnie jeden obiekt klasy DatabaseContext
            // (warto przy tym zapoznać się ze wzorcem singleton)
            _kernel.Bind<DatabaseContext>().To<DatabaseContext>().InSingletonScope();


            _kernel.Bind<IStuffQuery>().To<StuffQuery>();
            _kernel.Bind<IReadRepository<Student>>().To<ReadRepository<Student>>();
            _kernel.Bind<IReadRepository<Announcement>>().To<ReadRepository<Announcement>>();
        }
    }
}