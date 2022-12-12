using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace CURLdotNET
{
    public class CURLInit
    {
        [DllImport(@"curl_dll_lib.dll")]
        public static extern bool InitCURL(string hostname);
        public bool CURL_Init(string hostname_ip)
        {
            if(InitCURL(hostname_ip))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
}
