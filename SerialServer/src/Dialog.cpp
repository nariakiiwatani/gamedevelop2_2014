#include "Dialog.h"
#include <Cocoa/Cocoa.h>

std::string systemComboBoxSelector(const std::string &question, const std::vector<std::string> &list)
{
	NSAlert *alert = [[[NSAlert alloc] init] autorelease];
	[alert addButtonWithTitle:@"OK"];
//	[alert addButtonWithTitle:@"Cancel"];
	[alert setMessageText:[NSString stringWithCString:question.c_str()
											 encoding:NSUTF8StringEncoding]];
	// create combo box
	NSComboBox* box = [[NSComboBox alloc] initWithFrame:NSRectFromCGRect(CGRectMake(0,0,300,25))];
	for(auto name : list) {
		[box addItemWithObjectValue:[NSString stringWithCString:name.c_str() encoding:NSUTF8StringEncoding]];
	}
	if(!list.empty()) {
		[box selectItemAtIndex:0];
	}
	[alert setAccessoryView:box];
	NSInteger returnCode = [alert runModal];
	std::string text = "";
	if ( returnCode == NSAlertFirstButtonReturn )
		text = [[box stringValue] UTF8String];
	return text;
}
