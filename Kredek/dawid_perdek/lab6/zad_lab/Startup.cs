using Microsoft.Owin;
using Owin;

[assembly: OwinStartupAttribute(typeof(DawidPerdekLab6.Startup))]
namespace DawidPerdekLab6
{
    public partial class Startup
    {
        public void Configuration(IAppBuilder app)
        {
            ConfigureAuth(app);
        }
    }
}
