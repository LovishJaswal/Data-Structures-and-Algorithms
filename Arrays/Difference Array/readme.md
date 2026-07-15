# Difference Array

## Core Idea

When a problem involves **multiple range updates**, don't update every
element in the range.

Instead, record only where the update starts and where it ends, then
reconstruct the final array using a prefix sum.

---

## Recognition Triggers

Ask yourself:

- Are there many range updates?
- Am I updating every element repeatedly?
- Can I mark only the start and end of each update?
- Can the final array be built after processing all updates?

---

## Common Observations

### Range Increment

Instead of updating every index in `[l, r]`:

```
diff[l] += value
diff[r + 1] -= value
```

---

### Prefix Sum Reconstruction

After all updates:

```
answer[i] = answer[i - 1] + diff[i]
```

The prefix sum converts the difference array back into the final array.

---

## Problems Solved

| Problem | Key Observation |
|---------|------------------|
| Corporate Flight Bookings | Convert range bookings into boundary updates |
| Car Pooling | Track passenger changes at pickup and drop-off locations |
| Shifting Letters II | Mark shift ranges and reconstruct cumulative shifts |

---

## Optimization Mindset

1. Avoid updating every element in a range.
2. Store only boundary changes.
3. Apply all updates first.
4. Reconstruct the final array using a prefix sum.

---

## Mental Checklist

Before coding, ask:

☐ Are there multiple range updates?

☐ Am I repeatedly updating the same indices?

☐ Can I record only the start and end of each update?

☐ Can a prefix sum rebuild the final array?

---

## Keywords

Range Update

Boundary Updates

Difference Array

Prefix Sum

Offline Processing

Lazy Updates