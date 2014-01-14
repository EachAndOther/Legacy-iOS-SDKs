//
//
//    Copyright (c) 2005-2006 Apple Computer, Inc.
//    All rights reserved.
//
//    This document is the property of Apple Computer, Inc. It is
//    considered confidential and proprietary information.
//
//    This document may not be reproduced or transmitted in any form,
//    in whole or in part, without the express written permission of
//    Apple Computer, Inc.
//

#ifndef __NON_COPYABLE_H
#define __NON_COPYABLE_H

/// Base class for any class that should not be copied.
class NonCopyable
{
public:
	NonCopyable() {}
private:
	// These functions are private so this object cannot be copied.
	NonCopyable(const NonCopyable&);
	NonCopyable& operator=(const NonCopyable&);
};

#endif
