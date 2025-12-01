package main

import (
"fmt"
"math"
"math/rand"
"time"
"unsafe"
)

// SkipListNode represents a node in the SkipList
type SkipListNode struct {
key     int
forward []*SkipListNode
}

// SkipList represents the SkipList data structure
type SkipList struct {
header *SkipListNode
level  int
}

// NewSkipList creates a new SkipList instance
func NewSkipList() *SkipList {
return &SkipList{
header: &SkipListNode{
key:     math.MinInt32,
forward: make([]*SkipListNode, 17), // MAX_LEVEL + 1
},
level: 0,
}
}

// randomLevel generates a random level for new nodes
func (sl *SkipList) randomLevel() int {
level := 0
for rand.Float64() < 0.5 && level < 16 { // MAX_LEVEL
level++
}
return level
}

// Search finds a key in the SkipList. O(log n) average time.
func (sl *SkipList) Search(key int) *SkipListNode {
current := sl.header
for i := sl.level; i >= 0; i-- {
for current.forward[i] != nil && current.forward[i].key < key {
current = current.forward[i]
}
}

current = current.forward[0]
if current != nil && current.key == key {
return current
}
return nil
}

// Insert adds a key to the SkipList. O(log n) average time.
func (sl *SkipList) Insert(key int) {
update := make([]*SkipListNode, 17) // MAX_LEVEL + 1
current := sl.header

for i := sl.level; i >= 0; i-- {
for current.forward[i] != nil && current.forward[i].key < key {
current = current.forward[i]
}
update[i] = current
}

current = current.forward[0]

if current == nil || current.key != key {
newLevel := sl.randomLevel()

if newLevel > sl.level {
for i := sl.level + 1; i <= newLevel; i++ {
update[i] = sl.header
}
sl.level = newLevel
}

newNode := &SkipListNode{
key:     key,
forward: make([]*SkipListNode, newLevel+1),
}

for i := 0; i <= newLevel; i++ {
newNode.forward[i] = update[i].forward[i]
update[i].forward[i] = newNode
}
}
}

// Delete removes a key from the SkipList. O(log n) average time.
func (sl *SkipList) Delete(key int) {
update := make([]*SkipListNode, 17) // MAX_LEVEL + 1
current := sl.header

for i := sl.level; i >= 0; i-- {
for current.forward[i] != nil && current.forward[i].key < key {
current = current.forward[i]
}
update[i] = current
}

current = current.forward[0]

if current != nil && current.key == key {
for i := 0; i <= sl.level; i++ {
if update[i].forward[i] != current {
break
}
update[i].forward[i] = current.forward[i]
}

for sl.level > 0 && sl.header.forward[sl.level] == nil {
sl.level--
}
}
}

// Display prints the SkipList structure
func (sl *SkipList) Display() {
fmt.Println("SkipList structure:")
for level := sl.level; level >= 0; level-- {
current := sl.header.forward[level]
fmt.Printf("Level %d: ", level)
for current != nil {
fmt.Printf("%d -> ", current.key)
current = current.forward[level]
}
fmt.Println("None")
}
}

// Demonstrates SkipList operations with probabilistic balancing.
// Inserts 10 elements, searches for values, and displays structure.
func main() {
rand.Seed(time.Now().UnixNano())
startTime := time.Now()

// Create SkipList instance
skipList := NewSkipList()

// Insert elements
elements := []int{3, 6, 7, 9, 12, 19, 17, 26, 21, 25}
for _, elem := range elements {
skipList.Insert(elem)
}

// Calculate memory usage (approximate)
memoryUsed := unsafe.Sizeof(*skipList)

// Display structure
skipList.Display()

// Search operations
searchKeys := []int{19, 15, 21}
fmt.Println("\nSearch results:")
for _, key := range searchKeys {
result := skipList.Search(key)
found := "Not found"
if result != nil {
found = "Found"
}
fmt.Printf("Search for %d: %s\n", key, found)
}

// Delete operation
skipList.Delete(17)
fmt.Println("\nAfter deleting 17:")
skipList.Display()

elapsed := time.Since(startTime)

// Performance statistics
fmt.Println("\n--- Performance Statistics ---")
fmt.Printf("Execution time: %.4f ms\n", float64(elapsed.Nanoseconds())/1e6)
fmt.Printf("Memory usage: %d bytes\n", memoryUsed)
fmt.Println("\nTime Complexity (Average):")
fmt.Println("  - Search: O(log n)")
fmt.Println("  - Insert: O(log n)")
fmt.Println("  - Delete: O(log n)")
fmt.Println("  - Space: O(n)")
}
