#include <iostream>
#include <vector>

class Heap {
private:
    std::vector<int> m_heapTree;
    
public:
    Heap() { m_heapTree.resize(1); }
    
    Heap (int data) {
        Heap();
        insert(data);
    }
    Heap (const std::vector<int> &dataArray) {
        Heap();
        insertArray(dataArray);
    }
    
    void insert (int data);
    void insertArray (const std::vector<int> &dataArray);
    void deleteRoot ();
    
    ~Heap() {}
};

void Heap::insert (int data) {
    
    m_heapTree.push_back(data);
    
    if (m_heapTree.size() == 2) {
        return;
    }
    else {
        
        int i = (int)m_heapTree.size() - 1;
        int dataToSort = m_heapTree.at(i);
        
        while (i > 1 && m_heapTree.at(i) > m_heapTree.at(i/2)) {
            
            m_heapTree.at(i) = m_heapTree.at(i/2);
            i = i/2;
        }
        m_heapTree.at(i) = dataToSort;
    }
}

void Heap::insertArray (const std::vector<int> &dataArray) {
    
    for (int i(0); i < dataArray.size(); ++i) {
        this->insert(dataArray.at(i));
    }
}

void Heap::deleteRoot () {
    
    int curr (1);
    int child (curr * 2);
    int arrSize = int(m_heapTree.size());
    
    m_heapTree.at(1) = m_heapTree.at(arrSize - 1);
    while (child < arrSize - 1) {
        
        if (m_heapTree.at(child + 1) > m_heapTree.at(child)) {
            child++;
        }
        if (m_heapTree.at(curr) < m_heapTree.at(child)) {
            std::swap(m_heapTree.at(curr), m_heapTree.at(child));
            curr = child;
            child *= 2;
        }
        else { break; }
    }
}
