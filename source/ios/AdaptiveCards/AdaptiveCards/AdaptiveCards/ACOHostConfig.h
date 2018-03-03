//
//  ACRHostConfig.h
//  ACRHostConfig
//
//  Copyright © 2017 Microsoft. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ACOHostConfigParseResult.h"

@interface ACOHostConfig:NSObject

@property NSString *fontFamilyName;

- (instancetype)init;

+ (ACOHostConfigParseResult *)fromJson:(NSString *)payload;

@end    
