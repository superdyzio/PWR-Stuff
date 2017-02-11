using Microsoft.Owin;
using Owin;

[assembly: OwinStartupAttribute(typeof(DawidPerdekZad7.Startup))]
namespace DawidPerdekZad7
{
    public partial class Startup
    {
        public void Configuration(IAppBuilder app)
        {
            ConfigureAuth(app);
        }
    }
}
