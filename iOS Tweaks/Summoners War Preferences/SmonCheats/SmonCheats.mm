#import <Preferences/Preferences.h>

@interface SmonCheatsListController: PSListController {
}
@end

@implementation SmonCheatsListController
- (id)specifiers {
	if(_specifiers == nil) {
		_specifiers = [[self loadSpecifiersFromPlistName:@"SmonCheats" target:self] retain];
	}
	return _specifiers;
}

-(void)respring {
         system("killall -9 SpringBoard");
}
@end

// vim:ft=objc
