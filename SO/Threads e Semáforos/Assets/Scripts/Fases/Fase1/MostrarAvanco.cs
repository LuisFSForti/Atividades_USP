using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MostrarAvanco : MonoBehaviour
{
    //O controlador de recursos da fase
    [SerializeField] private RecursosController _controladorRecrusos;
    //A mensagem anterior que deve sumir e a nova de aviso
    [SerializeField] private GameObject _avisoEspera, _avisoAvanco;

    private void Update()
    {
        //Se n�o estiverem todos os recursos dispon�veis
        if (!_controladorRecrusos.TodosDisponiveis())
        {
            //Desativa a mensagem anterior
            _avisoEspera.SetActive(false);
            //Ativa a nova
            _avisoAvanco.SetActive(true);
            //Destr�i este script
            Destroy(this);
        }
    }
}
