using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class EsperandoOutrosRecursos : MonoBehaviour
{
    //O controlador de recursos da fase
    [SerializeField] private RecursosController _controladorRecursos;
    //A barra de progresso da thread
    [SerializeField] private Image _barraProgresso;
    //O objeto da mensagem de aviso
    [SerializeField] private GameObject _mensagemEsperando;

    private void Update()
    {
        //Se n�o estiverem todos os recursos dispon�veis e a thread estiver amarela (esperando)
        if(!_controladorRecursos.TodosDisponiveis() && _barraProgresso.color == Color.yellow)
        {
            //Ativa a mensagem
            _mensagemEsperando.SetActive(true);
        }
        //Se a barra estiver verde (avan�ando)
        if(_barraProgresso.color == Color.green)
        {
            //Desativa a mensagem
            _mensagemEsperando.SetActive(false);
            //Destr�i este script
            Destroy(this);
        }
    }
}
