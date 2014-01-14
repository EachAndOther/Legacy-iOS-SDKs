/*
 *  CMMotionManager.h
 *  CoreMotion
 *
 *  Copyright (c) 2010 Apple Inc. All rights reserved.
 *
 */

#import <Foundation/Foundation.h>

#import <CoreMotion/CMAccelerometer.h>
#import <CoreMotion/CMGyro.h>
#import <CoreMotion/CMDeviceMotion.h>

/* 
 * There are two methods to receive data from CMMotionManager: push and pull.
 *
 * Before using either method, be sure to set the update interval property 
 * appropriate to the type of data you're interested in. These properties are:
 * accelerometerUpdateInterval, gyroUpdateInterval, and deviceMotionUpdateInterval.
 *
 * To use the pull method, simply call startAccelerometerUpdates, startGyroUpdates,
 * and/or startDeviceMotionUpdates, depending on the type of data desired. Then, 
 * whenever a new sample of data is desired, simply examine the appropriate 
 * CMMotionManager property (accelerometerData, gyroData, or deviceMotion).
 *
 * To use the push method, simply call startAccelerometerUpdatesToQueue:withHandler:,
 * startGyroUpdatesToQueue:withHandler:, and/or 
 * startDeviceMotionUpdatesToQueue:withHandler:, depending on the type of data 
 * desired. You'll need to pass an NSOperationQueue and block to each call. When a new sample of 
 * data arrives, a new instance of the block will be added to the appropriate NSOperationQueue.
 * When you stop the updates (see below), all operations in the given NSOperationQueue will be 
 * cancelled, so it is recommended to pass CMMotionManager a queue that will not be used in other 
 * contexts.
 *
 * Regardless of whether you used push or pull, when you're done, be sure to call the stop method 
 * appropriate for the type of updates you started.  These methods are: stopAccelerometerUpdates,
 * stopGyroUpdates, and stopDeviceMotionUpdates.
 *
 */

/*
 *  CMAccelerometerHandler
 *  
 *  Discussion:
 *    Typedef of block to be invoked when accelerometer data is available.
 */
typedef void (^CMAccelerometerHandler)(CMAccelerometerData *accelerometerData, NSError *error);

/*
 *  CMGyroHandler
 *  
 *  Discussion:
 *    Typedef of block to be invoked when gyro data is available.
 */
typedef void (^CMGyroHandler)(CMGyroData *gyroData, NSError *error);

/*
 *  CMDeviceMotionHandler
 *  
 *  Discussion:
 *    Typedef of block to be invoked when device motion data is available.
 */
typedef void (^CMDeviceMotionHandler)(CMDeviceMotion *motion, NSError *error);

/*
 *  CMMotionManager
 *  
 *  Discussion:
 *    The CMMotionManager object is your entry point to the motion service.
 */
NS_CLASS_AVAILABLE(NA,4_0)
@interface CMMotionManager : NSObject
{
@private
	id _internal;
}

/*
 *  accelerometerUpdateInterval
 *  
 *  Discussion:
 *      The interval at which to deliver accelerometer data to the specified 
 *			handler once startAccelerometerUpdatesToQueue:withHandler: is called. 
 *			The units are in seconds. The value of this property is capped to 
 *			certain minimum and maximum values. The maximum value is determined by 
 *			the maximum frequency supported by the hardware. If sensitive to the 
 *			interval of acceleration data, an application should always check the 
 *			timestamps on the delivered CMAcceleration instances to determine the 
 *			true update interval. 
 */
@property(assign, nonatomic) NSTimeInterval accelerometerUpdateInterval;

/*
 *  accelerometerAvailable
 *  
 *  Discussion:
 *      Determines whether accelerometer is available.
 */
@property(readonly, nonatomic, getter=isAccelerometerAvailable) BOOL accelerometerAvailable;

/*
 *  accelerometerActive
 *  
 *  Discussion:
 *      Determines whether the CMMotionManager is currently providing 
 *			accelerometer updates.
 */
@property(readonly, nonatomic, getter=isAccelerometerActive) BOOL accelerometerActive;

/*
 *  accelerometerData
 *  
 *  Discussion:
 *      Returns the latest sample of accelerometer data, or nil if none is available.
 */

@property(readonly) CMAccelerometerData *accelerometerData;

/*
 *  startAccelerometerUpdates
 *  
 *  Discussion:
 *			Starts accelerometer updates with no handler. To receive the latest accelerometer data
 *			when desired, examine the accelerometerData property.
 */
- (void)startAccelerometerUpdates;

/*
 *  startAccelerometerUpdatesToQueue:withHandler:
 *  
 *  Discussion:
 *			Starts accelerometer updates, providing data to the given handler through the given queue.
 *			Note that when the updates are stopped, all operations in the 
 *			given NSOperationQueue will be cancelled.
 */
- (void)startAccelerometerUpdatesToQueue:(NSOperationQueue *)queue withHandler:(CMAccelerometerHandler)handler;

/*
 *  stopAccelerometerUpdates
 *  
 *  Discussion:
 *			Stop accelerometer updates.
 */
- (void)stopAccelerometerUpdates;

/*
 *  gyroUpdateInterval
 *  
 *  Discussion:
 *      The interval at which to deliver gyro data to the specified 
 *			handler once startGyroUpdatesToQueue:withHandler: is called. 
 *			The units are in seconds. The value of this property is capped to 
 *			certain minimum and maximum values. The maximum value is determined by 
 *			the maximum frequency supported by the hardware. If sensitive to the 
 *			interval of gyro data, an application should always check the 
 *			timestamps on the delivered CMGyroData instances to determine the 
 *			true update interval. 
 */
@property(assign, nonatomic) NSTimeInterval gyroUpdateInterval;

/*
 *  gyroAvailable
 *  
 *  Discussion:
 *      Determines whether gyro is available.
 */
@property(readonly, nonatomic, getter=isGyroAvailable) BOOL gyroAvailable;

/*
 *  gyroActive
 *  
 *  Discussion:
 *      Determines whether the CMMotionManager is currently providing gyro updates.
 */
@property(readonly, nonatomic, getter=isGyroActive) BOOL gyroActive;

/*
 *  gyroData
 *  
 *  Discussion:
 *		Returns the latest sample of gyro data, or nil if none is available.
 */
@property(readonly) CMGyroData *gyroData;

/*
 *  startGyroUpdates
 *  
 *  Discussion:
 *			Starts gyro updates with no handler. To receive the latest gyro data
 *			when desired, examine the gyroData property.
 */
- (void)startGyroUpdates;

/*
 *  startGyroUpdatesToQueue:withHandler:
 *  
 *  Discussion:
 *			Starts gyro updates, providing data to the given handler through the given queue. 
 *			Note that when the updates are stopped, all operations in the 
 *			given NSOperationQueue will be cancelled.

 */
- (void)startGyroUpdatesToQueue:(NSOperationQueue *)queue withHandler:(CMGyroHandler)handler;


/*
 *  stopGyroUpdates
 *  
 *  Discussion:
 *			Stops gyro updates.
 */
- (void)stopGyroUpdates;

/*
 *  deviceMotionUpdateInterval
 *  
 *  Discussion:
 *      The interval at which to deliver device motion data to the specified 
 *			handler once startDeviceMotionUpdatesToQueue:withHandler: is called. 
 *			The units are in seconds. The value of this property is capped to 
 *			certain minimum and maximum values. The maximum value is determined by 
 *			the maximum frequency supported by the hardware. If sensitive to the 
 *			interval of device motion data, an application should always check the 
 *			timestamps on the delivered CMDeviceMotion instances to determine the 
 *			true update interval. 
 */
@property(assign, nonatomic) NSTimeInterval deviceMotionUpdateInterval;

/*
 *  deviceMotionAvailable
 *  
 *  Discussion:
 *      Determines whether device motion is available.
 */
@property(readonly, nonatomic, getter=isDeviceMotionAvailable) BOOL deviceMotionAvailable;

/*
 *  deviceMotionActive
 *  
 *  Discussion:
 *      Determines whether the CMMotionManager is currently providing device
 *			motion updates.
 */
@property(readonly, nonatomic, getter=isDeviceMotionActive) BOOL deviceMotionActive;

/*
 *  deviceMotion
 *  
 *  Discussion:
 *		Returns the latest sample of device motion data, or nil if none is available.
 */
@property(readonly) CMDeviceMotion *deviceMotion;

/*
 *  startDeviceMotionUpdates
 *  
 *  Discussion:
 *			Starts device motion updates with no handler. To receive the latest device motion data
 *			when desired, examine the deviceMotion property.
 */
- (void)startDeviceMotionUpdates;

/*
 *  startDeviceMotionUpdatesToQueue:withHandler:
 *  
 *  Discussion:
 *			Starts device motion updates, providing data to the given handler through the given queue.
 *			Note that when the updates are stopped, all operations in the 
 *			given NSOperationQueue will be cancelled.

 */
- (void)startDeviceMotionUpdatesToQueue:(NSOperationQueue *)queue withHandler:(CMDeviceMotionHandler)handler;

/*
 *  stopDeviceMotionUpdates
 *  
 *  Discussion:
 *			Stops device motion updates.
 */
- (void)stopDeviceMotionUpdates;

@end
