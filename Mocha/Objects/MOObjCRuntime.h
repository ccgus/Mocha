//
//  MOObjCRuntime.h
//  Mocha
//
//  Created by Logan Collins on 5/16/12.
//  Copyright (c) 2012 Sunflower Softworks. All rights reserved.
//

#import <Foundation/Foundation.h>


@class MOProtocol;


/*!
 * @class MOObjCRuntime
 * @abstract Interface bridge to the Objective-C runtime
 */
@interface MOObjCRuntime : NSObject

/*!
 * @method sharedRuntime
 * @abstract Gets the shared runtime instance
 * 
 * @result An MOObjCRuntime object
 */
+ (MOObjCRuntime *)sharedRuntime;


/*!
 * @property classes
 * @abstract Gets the names of all classes registered with the runtime
 * 
 * @discussion
 * This method will ignore any classes that begin with an underscore, as
 * convention is that they are considered private.
 * 
 * @result An NSArray of NSString objects
 */
@property (copy, readonly) NSArray *classes;

/*!
 * @method classWithName:
 * @abstract Gets the class with a specified name
 * 
 * @param name
 * The name of the class
 * 
 * @discusion
 * This method is equivalent to NSClassFromString(name)
 * 
 * @result A Class object
 */
- (Class)classWithName:(NSString *)name;

/*!
 * @property protocols
 * @abstract Gets the names of all protocols registered with the runtime
 * 
 * @discussion
 * This method will ignore any protocols that begin with an underscore, as
 * convention is that they are considered private.
 * 
 * @result An NSArray of NSString objects
 */
@property (copy, readonly) NSArray *protocols;

/*!
 * @method protocolWithName:
 * @abstract Gets the protocol with a specified name
 * 
 * @param name
 * The name of the protocol
 * 
 * @discusion
 * This method returns an MOProtocol object, which is a thin wrapper around
 * an Objective-C Protocol object. See MOProtocol.h for more details.
 * As such, this method is not equivalent to NSProtocolFromString(name).
 * 
 * @result An MOProtocol object
 */
- (MOProtocol *)protocolWithName:(NSString *)name;

@end
