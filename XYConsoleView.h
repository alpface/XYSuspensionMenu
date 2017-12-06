//
//  XYConsoleView.h
//  XYConsoleView
//
//  Created by xiaoyuan on 05/12/2017.
//  Copyright © 2017 xiaoyuan. All rights reserved.
//

#ifdef __OBJC__

#pragma clang diagnostic ignored "-Wignored-attributes"

#ifdef DEBUG
    #define DLog(frmt, ...) \
        xy_log((@"<%s : %d> %s  " frmt), [[[NSString stringWithUTF8String:__FILE__] lastPathComponent] UTF8String], __LINE__, __PRETTY_FUNCTION__,  ##__VA_ARGS__);
#else
    #define DLog(...)
#endif


#import <Foundation/Foundation.h>

FOUNDATION_EXPORT NSNotificationName const XYConsoleDidChangeLogNotification;

FOUNDATION_EXPORT void xy_log(NSString *format, ...) NS_FORMAT_FUNCTION(1,2) NS_NO_TAIL_CALL;

#endif 

#import "XYSuspensionMenu.h"

@class XYConsoleTextView, XYConsoleView;

@interface UIApplication (XYConsole)

@property (nonatomic) XYConsoleView *xy_consoleView;

- (XYConsoleView *)xy_showConsoleWithCompletion:(void (^)(BOOL finished))completion;
- (BOOL)xy_hideConsoleWithCompletion:(void (^)(BOOL finished))completion;
- (void)xy_toggleConsoleWithCompletion:(void (^)(BOOL finished))completion;

@end


@interface XYConsoleTextView : UITextView

@end

@interface XYConsoleView : SuspensionWindow

@property (nonatomic, strong) XYConsoleTextView *consoleTextView;

@property (nonatomic, copy) NSString *text;

@end