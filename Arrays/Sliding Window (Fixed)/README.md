# Sliding Window (Fixed)

## Core Idea

Maintain a window of fixed size while moving through the array or
string.

Instead of recomputing the answer for every window, reuse the previous
window's result by removing the outgoing element and adding the incoming
element.

---

## Recognition Triggers

Ask yourself:

- Does the problem ask about a subarray or substring of size `k`?
- Is the window size fixed throughout the problem?
- Can I update the answer by processing only two elements?
- Am I repeatedly calculating the same information for overlapping windows?

---

## Common Observations

### Build the First Window

Compute the answer for the first window of size `k`.

---

### Slide the Window

When moving one step:

- Add the incoming element.
- Remove the outgoing element.

---

### Maintain Running State

Track only the information needed, such as:

- Window Sum
- Count
- Frequency
- Maximum / Minimum

---

### Update the Answer

After every window shift, update the required answer using the current
window.

---

## Problems Solved

| Problem | Key Observation |
|---------|------------------|
| Maximum Average Subarray I | Maintain the running sum of a fixed-size window. |
| Maximum Number of Vowels in a Substring of Given Length | Keep the vowel count while sliding the window. |
| Minimum Recolors to Get K Consecutive Black Blocks | The number of operations equals the number of white blocks in the current window. |

---

## Optimization Mindset

1. Compute the first window only once.
2. Never recompute an entire window.
3. Only process the incoming and outgoing elements.
4. Maintain just enough information to answer the problem.

---

## Mental Checklist

Before coding, ask:

☐ Is the window size fixed?

☐ Can I compute the first window separately?

☐ What changes when the window moves?

☐ What information should I maintain?

☐ Can I update the answer in O(1) for each slide?

---

## Template

```cpp
// Build the first window
for (...) {
    // Process first k elements
}

// Slide the window
for (...) {
    // Add incoming element

    // Remove outgoing element

    // Update answer
}
```

---

## Keywords

Fixed Window

Window Sum

Running Count

Incoming Element

Outgoing Element

Constant-Time Update

Sliding Window