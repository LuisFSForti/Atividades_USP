using System.Collections;
using System.Collections.Generic;
using TMPro;
using UnityEngine;

public class AvancouCiclo : MonoBehaviour
{
    //O controlador de recursos da fase
    [SerializeField] private RecursosController _controladorRecursos;
    //O componente de texto do recurso (a multiplicidade de ciclos)
    [SerializeField] private TMP_Text _texto;
    //O objeto da mensagem de aviso
    [SerializeField] private GameObject _mensagem;

    //Para verificar se o texto mudou
    private string _textoAnterior = "";

    void Update()
    {
        //Se o texto estiver diferente do anterior
        if(_texto.text != _textoAnterior)
        {
            //Se todos os recursos estão disponíveis
            if(_controladorRecursos.TodosDisponiveis())
            {
                //Apenas atualiza o texto
                _textoAnterior = _texto.text;
            }
            //Se não estiverem todos disponíveis
            else
            {
                //Ativa a mensagem
                _mensagem.SetActive(true);
                //Destrói este script
                Destroy(this);
            }
        }
    }
}
