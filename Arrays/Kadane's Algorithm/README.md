# Kadane's Algorithm

## Core Idea

Maintain the best subarray ending at the current index.

At every element, decide whether to:

- Extend the current subarray.
- Start a new subarray.

This reduces many subarray optimization problems from **O(n²)**
to **O(n)**.

---

## Recognition Triggers

Ask yourself:

- Am I looking for a contiguous subarray?
- Does the current answer depend only on the previous subarray?
- Should I continue the current subarray or start a new one?
- Can I maintain only the best subarray ending here?
- Can this be solved in one linear pass?

---

## Common Variations

### Maximum Subarray

Find the largest subarray sum.

**Example**
- Maximum Subarray (LeetCode 53)

---

### Maximum + Minimum Subarray

Run Kadane twice.

Used when both the maximum and minimum subarrays are needed.

**Example**
- Maximum Absolute Sum of Any Subarray (LeetCode 1749)

---

### Circular Subarray

A wrapped subarray equals:

**Total Sum − Minimum Subarray**

Run Kadane twice.

**Example**
- Maximum Sum Circular Subarray (LeetCode 918)

---

## Problems Solved

| Problem | Key Observation |
|---------|------------------|
| Maximum Subarray | Extend or start a new subarray |
| Maximum Absolute Sum of Any Subarray | Run Kadane for both maximum and minimum subarrays |
| Maximum Sum Circular Subarray | Wrapped Sum = Total Sum − Minimum Subarray |

---

## Optimization Mindset

1. Think in terms of subarrays ending at the current index.
2. Store only the previous state instead of a DP array.
3. Decide whether to continue or restart.
4. Adapt Kadane for different variants (maximum, minimum, circular).

---

## Mental Checklist

Before coding, ask:

☐ Is the problem about contiguous subarrays?

☐ Can I extend the previous subarray?

☐ Should I restart at the current element?

☐ Do I need both maximum and minimum subarrays?

☐ Is there a circular array observation?

---

## Keywords

Kadane's Algorithm

Dynamic Programming

Space Optimization

Maximum Subarray

Minimum Subarray

Circular Array

Running Sum

Greedy + DP