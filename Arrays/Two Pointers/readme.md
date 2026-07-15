# Two Pointers

## Core Idea

Use two indices to traverse the array efficiently.

Instead of repeatedly scanning the same elements, move one or both
pointers based on the problem's condition.

---

## Recognition Triggers

Ask yourself:

- Am I working with a sorted array?
- Can two indices replace nested loops?
- Can one pointer move independently of the other?
- Can moving a pointer eliminate unnecessary comparisons?

---

## Common Observations

### Opposite Ends

Start one pointer from the beginning and the other from the end.

---

### Same Direction

Move both pointers from left to right while maintaining a condition.

---

### Shrink the Search Space

Each pointer movement should reduce the remaining work without
revisiting previous elements.

---

## Optimization Mindset

1. Identify what each pointer represents.
2. Decide when each pointer should move.
3. Ensure every pointer movement makes progress.
4. Avoid revisiting the same elements.

---

## Mental Checklist

Before coding, ask:

☐ Can two pointers replace nested loops?

☐ Is the array sorted?

☐ When should the left pointer move?

☐ When should the right pointer move?

☐ Does each movement reduce the search space?

---

## Keywords

Two Pointers

Left Pointer

Right Pointer

Opposite Ends

Same Direction

Sorted Array

Search Space

Linear Traversal