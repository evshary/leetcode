#if 1
class MedianFinder {
private:
    priority_queue<int,vector<int>,less<int>> maxheap;
    priority_queue<int,vector<int>,greater<int>> minheap;
public:
    MedianFinder() {
        
    }
    void addNum(int num) {
        if (maxheap.empty() || maxheap.top() > num) {
            maxheap.push(num);
        } else {
            minheap.push(num);
        }
        if (maxheap.size() > minheap.size() + 1) {
            minheap.push(maxheap.top());
            maxheap.pop();
        } else if (minheap.size() > maxheap.size() + 1) {
            maxheap.push(minheap.top());
            minheap.pop();
        }
    }
    double findMedian() {
        if (maxheap.size() == minheap.size()) return ((double)(maxheap.top() + minheap.top())) / 2;
        if (maxheap.size() > minheap.size())
            return maxheap.top();
        else
            return minheap.top();
    }
};
#else
#define OFFSET      100000
#define BUCKET_NUM  1001
#define BUCKET_SIZE 200

class MedianFinder {
private:
    vector<vector<int>> buckets;
    vector<bool> sorted;
    int total_num;
public:
    MedianFinder() :
        buckets(BUCKET_NUM),
        sorted(BUCKET_NUM, true),
        total_num(0)
    {
        
    }
    
    void addNum(int num) {
        int bidx = (num + OFFSET) / BUCKET_SIZE;
        buckets[bidx].push_back(num);
        sorted[bidx] = false;
        total_num++;
    }
    
    int getNumFromIdx(int idx) {
        for (int i = 0; i < buckets.size(); i++) {
            if (buckets[i].size() > idx) {
                if (sorted[i] == false) {
                    sort(buckets[i].begin(), buckets[i].end());
                    sorted[i] = true;
                }
                return buckets[i][idx];
            }
            idx -= buckets[i].size();
        }
        return -1;
    } 
    
    double findMedian() {
        if (total_num % 2 == 0) {
            int num1 = getNumFromIdx(total_num / 2);
            int num2 = getNumFromIdx((total_num / 2) - 1);
            return ((double)(num1 + num2)) / 2;
        } else {
            return (double)getNumFromIdx(total_num / 2);
        }
    }
};
#endif

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */