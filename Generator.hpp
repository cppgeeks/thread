#ifndef GENERATOR_HPP
#define GENERATOR_HPP 
#include <queue>
#include <mutex>
#include <random>
#include <thread>
#include <iostream>

class Generator{
    public:
                                            Generator();

                                            ~Generator();

                void                        Run();

                void                        Generate();

                void                        takeMutex();

                void                        setMutex();
                
                int                         takeNewInt();
                   
    private:
                std::thread                 m_thr_generate;  

                std::mutex                  m_mutex; 

                std::random_device          rd;

                std::queue<int>             m_queue;

};


#endif //GENERATE_HPP