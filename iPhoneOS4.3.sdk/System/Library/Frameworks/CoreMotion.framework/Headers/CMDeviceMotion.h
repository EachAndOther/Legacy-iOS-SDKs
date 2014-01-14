/*
 *  CMDeviceMotion.h
 *  CoreMotion
 *
 *  Copyright (c) 2010 Apple Inc. All rights reserved.
 *
 */

#import <CoreMotion/CMAccelerometer.h>
#import <CoreMotion/CMAttitude.h>
#import <CoreMotion/CMGyro.h>

/*
 *  CMDeviceMotion
 *  
 *  Discussion:
 *    A CMDeviceMotion object contains basic information about the device's
 *		motion.
 */
NS_CLASS_AVAILABLE(NA,4_0)
@interface CMDeviceMotion : CMLogItem
{
@private
	id _internal;
}

/*
 *  attitude
 *  
 *  Discussion:
 *    Returns the attitude of the device.
 *
 */
@property(readonly, nonatomic) CMAttitude *attitude;

/*
 *  rotationRate
 *  
 *  Discussion:
 *    Returns the rotation rate of the device.
 *
 */
@property(readonly, nonatomic) CMRotationRate rotationRate;

/*
 *  gravity
 *  
 *  Discussion:
 *    Returns the gravity vector expressed in the device's reference frame. Note
 *		that the total acceleration of the device is equal to gravity plus
 *		userAcceleration.
 *
 */
@property(readonly, nonatomic) CMAcceleration gravity;

/*
 *  userAcceleration
 *  
 *  Discussion:
 *    Returns the acceleration that the user is giving to the device. Note
 *		that the total acceleration of the device is equal to gravity plus
 *		userAcceleration.
 *
 */
@property(readonly, nonatomic) CMAcceleration userAcceleration;

@end
