use clipboard::{ClipboardContext, ClipboardProvider};
use uuid::Uuid;

fn main() {
    // Generate a new UUID (GUID)
    let guid = Uuid::new_v4();

    // Convert the GUID to a string
    let guid_string = guid.to_string();

    // Copy the GUID string to the clipboard
    let mut ctx: ClipboardContext = ClipboardProvider::new().expect("Failed to initialize clipboard context");
    ctx.set_contents(guid_string.clone()).expect("Failed to set clipboard contents");
}