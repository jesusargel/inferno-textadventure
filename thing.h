#ifndef THING_H
#define THING_H

#include <vector>
#include <string>

class Thing {
    private:
        std::string longName;
        std::string description;
        int type;
    public:
        std::string getLongName();
        void setLongName(std::string);
        std::string getDescription();
        void setDescription(std::string);
        int getType();
        void setType(int);
        
};

#endif

