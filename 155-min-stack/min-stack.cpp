class MinStack {

private:
    vector<int> data;
    int top_index;
    int min_value;

public:
    MinStack() {
        this->top_index = -1;
        this->min_value = INT_MAX;
    }

    void push(int val) {
        this->data.push_back(val);
        if (val <= min_value) {
            min_value = val;
        }

    }

    void pop() {
        int oldMin = this->data.back();
        this->data.pop_back();
        if (oldMin == min_value) {
            min_value = this->data.empty()? INT_MAX:*min_element(this->data.begin(), this->data.end());
        }
    }

    int top() {
        return this->data.back();
    }

    int getMin() {
        return min_value;
    }
};