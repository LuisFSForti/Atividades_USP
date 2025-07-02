using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ControleTempo : MonoBehaviour
{
    //Se o objeto deve parar o tempo ao ficar vis�vel/invis�vel
    [SerializeField] bool pausarTempoVisible, pausarTempoInvisible;

    //Ao carregar
    private void Awake()
    {
        //Pausa o tempo
        Time.timeScale = 0f;
    }

    //Ao ativar o objeto
    private void OnEnable()
    {
        //Pausa ou n�o o tempo de acordo com a var�avel "vis�vel"
        Time.timeScale = pausarTempoVisible ? 0f : 1f;
    }

    //Ao desativar o objeto
    private void OnDisable()
    {
        //Pausa ou n�o o tempo de acordo com a var�avel "invis�vel"
        Time.timeScale = pausarTempoInvisible ? 0f : 1f;
    }
}
