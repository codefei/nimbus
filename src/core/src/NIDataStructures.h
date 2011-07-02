//
// Copyright 2011 Jeff Verkoeyen
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#import <Foundation/Foundation.h>

#pragma mark -
#pragma mark Data Structures

/**
 * For classic computer science data structures.
 *
 * @ingroup NimbusCore
 * @defgroup Data-Structures Data Structures
 * @{
 *
 * iOS provides most of the important data structures such as arrays, dictionaries, and sets.
 * However, it is missing some lesser-used data structures such as linked lists and easy-to-use
 * trees structures.
 */

struct NILinkedListNode {
  id    object;
  struct NILinkedListNode* prev;
  struct NILinkedListNode* next;
};

typedef void NILinkedListLocation;

/**
 * A singly linked list implementation.
 *
 * This data structure is provided for constant time insertion and deletion of objects
 * in a collection.
 *
 * Example: Building a first-in-first-out list of operations.
 *
 * @code
 * NILinkedList* ll = [NILinkedList linkedList];
 * // Add the operations to the linked list like you would an array.
 * [ll addObject:operation1];
 * // Each addObject call appends the object to the end of the linked list.
 * [ll addObject:operation2];
 *
 * // Later on...
 *
 * NSOperation* op1 = [ll firstObject];
 * // Process the operation...
 *
 * // Remove the head of the linked list in constant time.
 * [ll removeFirstObject];
 * @endcode
 */
@interface NILinkedList : NSObject <NSCopying, NSCoding, NSFastEnumeration> {
@private
  struct NILinkedListNode* _head;
  struct NILinkedListNode* _tail;
  unsigned long _count;

  // Used internally to track modifications to the linked list.
  unsigned long _modificationNumber;
}

/**
 * The first object in the linked list.
 */
@property (nonatomic, readonly) id firstObject;

/**
 * The last object in the linked list.
 */
@property (nonatomic, readonly) id lastObject;

/**
 * The number of objects in the linked list.
 */
@property (nonatomic, readonly) unsigned long count;

/**
 * Designated initializer.
 */
- (id)init;

/**
 * Convenience method for creating an autoreleased linked list.
 *
 * Identical to [[[NILinkedList alloc] init] autorelease];
 */
+ (NILinkedList *)linkedList;

/**
 * Append an object to the linked list.
 *
 * Run-time: O(1)
 *
 * @returns A location within the linked list.
 */
- (NILinkedListLocation *)addObject:(id)object;

/**
 * Retrieve the object at a specific location.
 *
 * Run-time: O(1)
 */
- (id)objectAtLocation:(NILinkedListLocation *)location;

/**
 * Remove all objects from the linked list.
 *
 * Run-time: Theta(count)
 */
- (void)removeAllObjects;

/**
 * Remove an object from the linked list.
 *
 * Run-time: O(count)
 */
- (void)removeObject:(id)object;

/**
 * Remove the first object from the linked list.
 *
 * Run-time: O(1)
 */
- (void)removeFirstObject;

/**
 * Remove the last object from the linked list.
 *
 * Run-time: O(1)
 */
- (void)removeLastObject;


/**
 * @name Pseudo-index support
 * The following methods are provided to aid in accessing objects in the linked list in constant
 * time.
 * @{
 */
#pragma mark Pseudo-index support

/**
 * Search for an object in the linked list.
 *
 * Run-time: O(count)
 *
 * @returns A location within the linked list.
 */
- (NILinkedListLocation *)locationOfObject:(id)object;

/**
 * Remove an object at a predetermined location.
 *
 * Run-time: O(1)
 *
 * It is assumed that this location still exists in the linked list. If the object this
 * location refers to has since been removed then this method will have undefined results.
 *
 * This is provided as an optimization over the O(n) removal method but should be used with care.
 */
- (void)removeObjectAtLocation:(NILinkedListLocation *)location;

/**@}*/// End of Pseudo-index support

@end


///////////////////////////////////////////////////////////////////////////////////////////////////
/**@}*/// End of Data Structures //////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
