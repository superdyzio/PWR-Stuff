using Microsoft.Owin;
using Owin;

[assembly: OwinStartupAttribute(typeof(DawidPerdekZad6.Startup))]
namespace DawidPerdekZad6
{
    public partial class Startup
    {
        public void Configuration(IAppBuilder app)
        {
            ConfigureAuth(app);
        }
    }
}
