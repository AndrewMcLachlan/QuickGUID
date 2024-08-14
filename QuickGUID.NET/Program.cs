using System.Runtime.InteropServices;

[DllImport("user32.dll")]
static extern bool OpenClipboard(IntPtr hWndNewOwner);

[DllImport("user32.dll")]
static extern bool CloseClipboard();

[DllImport("user32.dll")]
static extern bool SetClipboardData(uint uFormat, IntPtr data);

OpenClipboard(IntPtr.Zero);
var guidString = Guid.NewGuid().ToString("D").ToLowerInvariant();
var ptr = Marshal.StringToHGlobalUni(guidString);
SetClipboardData(13, ptr);
CloseClipboard();
Marshal.FreeHGlobal(ptr);
