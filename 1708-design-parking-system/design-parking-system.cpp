class ParkingSystem {
private:
    int Bigsize;
    int Midsize;
    int Smallsize;
public:
    ParkingSystem(int big, int medium, int small) {
        Bigsize=big;
        Midsize=medium;
        Smallsize=small;
    }
    
    bool addCar(int carType) {
        if(carType==1){
            if(Bigsize>0){
                Bigsize--;
                return true;
            }
        }else if(carType==2){
            if(Midsize>0){
                Midsize--;
                return true;
            }
        }else if(carType==3){
            if(Smallsize>0){
                Smallsize--;
                return true;
            }
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */