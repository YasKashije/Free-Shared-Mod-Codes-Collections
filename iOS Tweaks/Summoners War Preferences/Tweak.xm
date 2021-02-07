#import <Foundation/Foundation.h>
#import "writeData.h"
#define PLIST_PATH @"/var/mobile/Library/Preferences/smoncheats.plist"

inline bool GetPrefBool(NSString *key)
{
return [[[NSDictionary dictionaryWithContentsOfFile:PLIST_PATH] valueForKey:key] boolValue];
}

%ctor {


if(GetPrefBool(@"kAcc"))
{
writeData(0x11212C,0x6420);
writeData(0x11212E,0x6421);
writeData(0x112130,0x4843);
writeData(0x112132,0x7047);
}
else
{

}

if(GetPrefBool(@"kCri"))
{
writeData(0x1120CC,0x6420);
writeData(0x1120CE,0x9621);
writeData(0x1120D0,0x4843);
writeData(0x1120D2,0x7047);
}
else
{

}

if(GetPrefBool(@"kCriDam"))
{
writeData(0x1120FC,0x6420);
writeData(0x1120FE,0x1021);
writeData(0x112100,0x4843);
writeData(0x112102,0x7047);
}
else
{

}

//CheckHackingTool
writeData(0x4F920,0xC046);
writeData(0x4F922,0x7047);

//InitHackingToolCheck
writeData(0x4F9B0,0xC046);
writeData(0xF9B42,0x7047);

//UpdateHackToolCheck 

//bndGetRunningHackingTool
writeData(0x1BFEEC,0xC046);
writeData(0x1BFEEE,0x7047);

//GetPlayerXigncodeDetected
writeData(0xD601C,0xC046);
writeData(0xD6024,0x7047);

//GetPlayerXigncodeErrorCode
writeData(0xD602C,0xC046);
writeData(0xD6034,0x7047);

}

%hook CKCocoUtils
+(bool)isJailbreak
{
return false;
}
%end

%hook FlurryUtil
+(bool)deviceIsJailbroken
{
return false;
}
%end

%hook CZDevice
+(bool)isJailbroken
{
return false;
}
%end

%hook FlurryUtil
-(bool)appIsCracked
{
return false;
}
%end

%hook SBJsonWriter
-(bool)humanReadable
{
return true;
}
%end

%hook SBJSON
-(bool)humanReadable
{
return true;
}
%end