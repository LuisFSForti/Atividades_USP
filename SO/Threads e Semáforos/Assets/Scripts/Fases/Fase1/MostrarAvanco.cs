using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MostrarAvanco : MonoBehaviour
{
    [SerializeField] private RecursosController _controladorRecrusos;
    [SerializeField] private GameObject _avisoEspera, _avisoAvanco;

    private void Update()
    {
        if (!_controladorRecrusos.TodosDisponiveis())
        {
            _avisoEspera.SetActive(false);
            _avisoAvanco.SetActive(true);
            Destroy(this);
        }
    }
}
