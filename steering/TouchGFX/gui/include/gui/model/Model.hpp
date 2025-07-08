#ifndef MODEL_HPP
#define MODEL_HPP

class ModelListener;

class Model
{
public:
    Model();

    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

    void tick();
    void initMenuItems();
protected:
    ModelListener* modelListener;
    int speed;
    int maxTemp;
    int avgTemp;
    int batteryLevel;
    int batteryPower;
};

#endif // MODEL_HPP
