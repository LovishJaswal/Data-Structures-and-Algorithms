# Sliding Window (Variable)

## Core Idea

Maintain a dynamic window using two pointers.

Unlike Fixed Sliding Window, the window size is not constant.
Expand the window by moving the right pointer and shrink it by moving
the left pointer whenever required.

Each element enters the window once and leaves the window once,
resulting in an O(n) solution.

---

## Recognition Triggers

Ask yourself:

- Am I working with a contiguous subarray or substring?
- Am I looking for the longest or shortest valid window?
- Does the window size change depending on a condition?
- Can two pointers maintain the required information?
- Can I avoid checking every possible subarray?

---

## Common Observations

### Expand the Window

Move the right pointer to include a new element.

---

### Shrink the Window

Move the left pointer until the window satisfies the required condition.

---

### Window Validity

The solution depends on maintaining a valid window.

The validity condition varies from problem to problem.

Examples include:

- Window sum
- Duplicate elements
- Distinct elements
- Frequency limits
- Custom constraints

---

### Every Element is Processed At Most Twice

Each element:

- Enters the window once.
- Leaves the window once.

Therefore,

Time Complexity = **O(n)**

---

## Two Common Forms

### Minimum Window

Expand the window.

Once the condition is satisfied, shrink as much as possible while
keeping the window valid.

---

### Maximum Window

Expand the window.

If the window becomes invalid, shrink until it becomes valid again.

---

## Optimization Mindset

1. Expand first.
2. Maintain the window property.
3. Shrink only when necessary.
4. Never move pointers backward.
5. Update the answer only when the window is in the correct state.

---

## Mental Checklist

Before coding, ask:

☐ What defines a valid window?

☐ What should I store while expanding?

☐ When should I move the left pointer?

☐ Is this a minimum or maximum window problem?

☐ Should I update the answer before or after shrinking?

☐ Which data structure helps maintain the window?

---

## Standard Templates

### Minimum Window

```cpp
add(right);

while(window is valid){
    update answer;
    remove(left);
}
```

---

### Maximum Window

```cpp
add(right);

while(window is invalid){
    remove(left);
}

update answer;
```

---

## Keywords

Sliding Window

Two Pointers

Dynamic Window

Expand

Shrink

Contiguous Subarray

Substring

Running Sum

HashMap

HashSet

Frequency Array

Frequency Map

Distinct Elements

Window Validity