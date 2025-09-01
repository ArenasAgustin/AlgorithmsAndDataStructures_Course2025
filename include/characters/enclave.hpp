#ifndef ENCLAVE_HPP
#define ENCLAVE_HPP

#include <iostream>

#include "entidadGenerica.hpp"
#include "randomEventGenerator.hpp"

/**
 * @class Enclave
 * @brief Representa una organización militar tecnológicamente avanzada en el Yermo.
 *
 * El Enclave es conocido por su tecnología avanzada y su enfoque militarista.
 * Su objetivo principal es restaurar el orden y la civilización, aunque sus métodos
 * pueden ser cuestionables.
 */
class Enclave : public EntidadGenerica
{
private:
    double m_fuerza;                                   ///< Nivel de ataque general
    bool m_detectado {false};                          ///< Indica si han sido detectados
    double m_deteccionChance;                          ///< Probabilidad de ser detectados
    RandomEventGenerator* m_randomgenerator {nullptr}; ///< Generador de eventos aleatorios

public:
    /**
     * @brief Constructor
     * @param nombre Nombre del grupo Enclave
     * @param fuerza Nivel de fuerza del Enclave
     * @param detectado Indica si han sido detectados
     */
    explicit Enclave(const std::string& nombre,
                     double fuerza,
                     bool detectado,
                     RandomEventGenerator* randomGenerator,
                     double deteccionChance)
        : EntidadGenerica(nombre)
        , m_fuerza(fuerza)
        , m_detectado(detectado)
        , m_deteccionChance(deteccionChance)
        , m_randomgenerator(randomGenerator) // 20% de posibilidad de ser detectados
    {
    }

    /**
     * @brief Muestra información del grupo raider
     */
    void showInfo() const override
    {
        std::cout << "🔫 ENCLAVE: " << m_name << "\n"
                  << " - Factor de fuerza: " << m_fuerza << "\n"
                  << " - ¿Detectados?: " << (m_detectado ? "Sí" : "No") << "\n";
    }

    /**
     * @brief Simula el intento de detección
     */
    void detectarse()
    {
        if (m_randomgenerator->chance(m_deteccionChance))
        {
            m_detectado = true;
            std::cout << "💬 " << m_name << " >>> Nos han detectado. Prepárense para el combate!" << '\n';
        }
        else
        {
            std::cout << "💬 " << m_name << " >>> Hemos evitado ser detectados... por ahora." << '\n';
        }
    }
};

#endif // ENCLAVE_HPP
