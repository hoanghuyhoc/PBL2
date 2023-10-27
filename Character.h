class Character
{
    private:   
        char* Name;
        int Level;
        double HP, MaxHP, ATK, DEF;
    public:
        Player(char*, int, double, double, double);
        ~Player();
        void setName();
        void setLevel();
        void setMaxHP();
};