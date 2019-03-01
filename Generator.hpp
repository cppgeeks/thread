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

                bool                        takeMutex(int token);

                void                        freeMutex(int token);
                
                int                         takeNewInt();

                int                         createRandomNumber(int from, int to );
                   
    private:

                std::thread                 m_thr_generate;  

                std::mutex                  m_mutex;

                bool                        m_control_mutex; 

                int                         m_token;

                std::random_device          rd;

                std::queue<int>             m_queue;

};


#endif //GENERATE_HPP