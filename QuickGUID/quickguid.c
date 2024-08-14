#include <windows.h>
#include <objbase.h>
#include <stdio.h>

int main() {
    // Generate a new GUID
    GUID guid;
    HRESULT hCreateGuid = CoCreateGuid(&guid);

    if (hCreateGuid != S_OK) {
        printf("Failed to create GUID\n");
        return 1;
    }

    // Convert GUID to string
    char guidString[37];
    snprintf(guidString, sizeof(guidString),
             "%08lX-%04X-%04X-%04X-%012llX",
             guid.Data1, guid.Data2, guid.Data3,
             (guid.Data4[0] << 8) | guid.Data4[1],
             *((unsigned long long*)&guid.Data4[2]));

    // Open the clipboard
    if (!OpenClipboard(NULL)) {
        printf("Failed to open clipboard\n");
        return 1;
    }

    // Empty the clipboard before setting data
    EmptyClipboard();

    // Allocate global memory for the GUID string
    HGLOBAL hGlob = GlobalAlloc(GMEM_MOVEABLE, strlen(guidString) + 1);
    if (hGlob == NULL) {
        printf("Failed to allocate memory\n");
        CloseClipboard();
        return 1;
    }

    // Copy GUID string to global memory
    memcpy(GlobalLock(hGlob), guidString, strlen(guidString) + 1);
    GlobalUnlock(hGlob);

    // Set the clipboard data
    if (SetClipboardData(CF_TEXT, hGlob) == NULL) {
        printf("Failed to set clipboard data\n");
        GlobalFree(hGlob);
        CloseClipboard();
        return 1;
    }

    // Close the clipboard
    CloseClipboard();

    return 0;
}