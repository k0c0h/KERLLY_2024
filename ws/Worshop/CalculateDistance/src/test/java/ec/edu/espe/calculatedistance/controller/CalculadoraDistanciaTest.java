
package ec.edu.espe.calculatedistance.controller;

import ec.edu.espe.calculatedistance.controller.CalculadoraDistancia;
import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

/**
 *
 * @author G403
 */
public class CalculadoraDistanciaTest {
    
    private CalculadoraDistancia calculadora = new CalculadoraDistancia();
    
    @Test
    public void testDistanciaPositiva() {
        double velocidad = 10;
        double tiempo = 2;
        double distanciaCalculada = calculadora.calcularDistancia(velocidad, tiempo);
        assertEquals(20, distanciaCalculada, 0.1); // El tercer parámetro es la precisión permitida
    }
    
    @Test
    public void testVelocidadCero() {
        double velocidad = 0;
        double tiempo = 5;
        double distanciaCalculada = calculadora.calcularDistancia(velocidad, tiempo);
        assertEquals(0, distanciaCalculada, 0.001);
    }
    
    @Test
    public void testTiempoCero() {
        double velocidad = 15;
        double tiempo = 0;
        double distanciaCalculada = calculadora.calcularDistancia(velocidad, tiempo);
        assertEquals(0, distanciaCalculada, 0.001);
    }
    
    @Test
    public void testValoresNegativos() {
        double velocidad = 12;
        double tiempo = 3;
        double distanciaCalculada = calculadora.calcularDistancia(velocidad, tiempo);
        assertEquals(-36, distanciaCalculada, 0.001);
    }
    
    @Test
    public void testValoresDecimales() {
        double velocidad = 7.5;
        double tiempo = 4.5;
        double distanciaCalculada = calculadora.calcularDistancia(velocidad, tiempo);
        assertEquals(33.75, distanciaCalculada, 0.001);
    }
    
    @Test
    public void testGrandesNumeros() {
        double velocidad = 1000;
        double tiempo = 0.1;
        double distanciaCalculada = calculadora.calcularDistancia(velocidad, tiempo);
        assertEquals(100, distanciaCalculada, 0.001);
    }
    
    @Test
    public void testTiempoGrande() {
        double velocidad = 20;
        double tiempo = 10000;
        double distanciaCalculada = calculadora.calcularDistancia(velocidad, tiempo);
        assertEquals(200000, distanciaCalculada, 0.001);
    }
}