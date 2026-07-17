# Binary Search on Arrays

## Core Idea

Don't search linearly.

Whenever the data is sorted, eliminate half of the search space after
every comparison.

Binary Search works because the search space is monotonic.

---

## Recognition Triggers

Ask yourself:

- Is the array sorted?
- Can I eliminate half the search space?
- Am I searching for an element or its position?
- Am I looking for the first or last occurrence?
- Can I modify Binary Search instead of returning immediately?
- Does the problem require O(log n) time?

---

## Common Binary Search Patterns

### Classic Binary Search

Search for the target directly.

**Use When**
- Need to determine whether a target exists.
- Need its exact index.

**Example**
- Binary Search

---

### Search Insert Position

Binary search even if the target doesn't exist.

**Use When**
- Need the index where the target should be inserted.
- Maintain sorted order.

**Example**
- Search Insert Position

---

### Left Boundary

Continue searching left even after finding the target.

**Use When**
- Need the first occurrence.

**Example**
- Find First and Last Position of Element in Sorted Array

---

### Right Boundary

Continue searching right even after finding the target.

**Use When**
- Need the last occurrence.

**Example**
- Find First and Last Position of Element in Sorted Array

---

## Problems Solved

| Problem | Key Idea |
|---------|----------|
| Binary Search | Eliminate half the search space |
| Search Insert Position | Return insertion index if target doesn't exist |
| Find First and Last Position of Element | Binary search twice to find left and right boundaries |

---

## Standard Template

```cpp
while (low <= high) {

    int mid = low + (high - low) / 2;

    if (nums[mid] == target) {
        // Found
    }
    else if (nums[mid] < target) {
        low = mid + 1;
    }
    else {
        high = mid - 1;
    }
}
```

---

## Optimization Mindset

1. Verify the array is sorted.
2. Define the search space.
3. Compute mid safely.
4. Decide which half can be discarded.
5. Modify Binary Search when searching for boundaries.

---

## Mental Checklist

Before coding, ask:

☐ Is the array sorted?

☐ Can I eliminate half the search space?

☐ Am I searching for an index or a boundary?

☐ Should I continue searching after finding the target?

☐ Is O(log n) expected?

---

## Keywords

Sorted Array

Binary Search

Mid

Low

High

Search Space

Left Boundary

Right Boundary

First Occurrence

Last Occurrence

Search Insert Position