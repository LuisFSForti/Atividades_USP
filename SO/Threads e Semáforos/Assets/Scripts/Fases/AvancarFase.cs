using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class AvancarFase : MonoBehaviour
{
    //Mensagem de fase concluída
    [SerializeField] private GameObject _mensagemFaseConcluida;

    //Lista dos controladores das threads
    private List<ThreadController> _controladoresDeThreads;

    //Carrega a próxima cena (avança de fase)
    public void Avancar()
    {
        SceneManager.LoadScene(SceneManager.GetActiveScene().buildIndex + 1);
    }

    private void Start()
    {
        //Pega todas as threads
        GameObject[] aux = GameObject.FindGameObjectsWithTag("Thread");

        //Pega todos os controladores das threads
        _controladoresDeThreads = new List<ThreadController>();
        foreach (GameObject thread in aux)
        {
            _controladoresDeThreads.Add(thread.GetComponent<ThreadController>());
        }
    }

    private void Update()
    {
        //Para cada thread
        for(int i = 0; i < _controladoresDeThreads.Count; i++)
        {
            //Se o controlador foi destruído
            if(_controladoresDeThreads[i] == null)
            {
                //Remove ele da lista de controladores
                _controladoresDeThreads.Remove(_controladoresDeThreads[i]);
                //Retorna i em 1 para não ter conflito com o loop
                i--;
            }
        }
        //Se não houverem mais controladores
        if(_controladoresDeThreads.Count == 0)
        {
            //Ativa a mensagem de fase concluída
            _mensagemFaseConcluida.SetActive(true);
        }
    }
}
