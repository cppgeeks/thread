#ifndef PRINTER_OUT_HPP
#define PRINTER_OUT_HPP
#include "Generator.hpp"

class Printer{
    public:
                        Printer();
                        
                        ~Printer();

            void        Run(Generator* m_gen);
    private:
            void        Print(Generator* m_gen);

            void        Init();  

            std::mutex  m_mutex;

            std::thread m_thr_printer_out;
};

#endif /// PRINT_OUT_HPP