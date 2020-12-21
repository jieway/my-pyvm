class HiInteger:public HiOject {

private:
    int _value;

public:
    HiInteger(int x);
    int value() {
        return _value;
    }
};