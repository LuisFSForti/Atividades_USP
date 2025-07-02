using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ControleTempo : MonoBehaviour
{
    //Se o objeto deve parar o tempo ao ficar visível/invisível
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
        //Pausa ou não o tempo de acordo com a varíavel "visível"
        Time.timeScale = pausarTempoVisible ? 0f : 1f;
    }

    //Ao desativar o objeto
    private void OnDisable()
    {
        //Pausa ou não o tempo de acordo com a varíavel "invisível"
        Time.timeScale = pausarTempoInvisible ? 0f : 1f;
    }
}
