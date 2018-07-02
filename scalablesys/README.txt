Scalable Systems Notes

1) Single Server Cache Design 
Eviction Strategy
 - FIFO
 - LRU
 - LFU
Access Pattern
 - Write through
 - write-around
 - write back
Size - based on use-case
Concurrency
Prefer low latency and high avail over consistency
  - low latency is very imp in caching

2) Memcached
1) how many shards
 - depends on single server qps - which is 50k qps default
 - distributed hashing / consistent hashing
   - code consistent hashing
 - design memory cache - start with single server and then expand to distributed
Reading links 
- http://codecapsule.com/2012/11/07/ikvs-implementing-a-key-value-store-table-of-contents/
- https://www.quora.com/Whats-the-maximum-throughput-in-queries-per-second-for-memcached-with-small-object-sizes
- http://www.tom-e-white.com/2007/11/consistent-hashing.html
- https://ivoroshilin.wordpress.com/2013/07/15/distributed-caching-under-consistent-hashing/
- latency.txt