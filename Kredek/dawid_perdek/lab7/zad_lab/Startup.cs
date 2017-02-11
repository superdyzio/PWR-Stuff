using Microsoft.Owin;
using Owin;

[assembly: OwinStartupAttribute(typeof(DawidPerdekLab7.Startup))]
namespace DawidPerdekLab7
{
    public partial class Startup
    {
        public void Configuration(IAppBuilder app)
        {
            ConfigureAuth(app);
        }
    }
}
