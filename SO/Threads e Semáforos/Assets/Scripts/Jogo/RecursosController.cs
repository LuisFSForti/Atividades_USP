using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using Unity.VisualScripting;
using UnityEngine;
using UnityEngine.UI;

//Enum com os recursos disponíveis
public enum Recursos
{
    Quadrado,
    Circulo,
    Triangulo,
    Losango,
    Estrela
}

public class RecursosController : MonoBehaviour
{
    //Lista com os prefabs dos recursos
    [SerializeField] private List<GameObject> _prefabRecursos;
    //Lista com slots de cada recurso
    [SerializeField] private List<RectTransform> _slotsRecursos;

    //Lista com os recursos disponíveis (não reservados)
    private List<int> _recursosDisponiveis;

    //Para verificar se um recurso está disponível
    public bool EstaDisponivel(int val)
    {
        return _recursosDisponiveis.Contains(val);
    }

    //Para definir que o recurso foi reservado por uma thread
    public void RecursoDado(int val)
    {
        _recursosDisponiveis.Remove(val);
    }

    //Para definir que o recurso foi liberado de uma thread
    public void RecursoLiberado(int val)
    {
        //Instancia o prefab do recurso
        GameObject recurso = Instantiate(_prefabRecursos[val], _slotsRecursos[val]);
        recurso.GetComponent<Image>().color = Color.black;

        //Adiciona ele à lista de recursos disponíveis
        _recursosDisponiveis.Add(val);
    }

    //Retorna a quantidade de itens disponíveis
    public int RecursosDisponiveis()
    {
        return _recursosDisponiveis.Count;
    }

    //Retorna se todos os recursos estão disponíveis
    public bool TodosDisponiveis()
    {
        return _recursosDisponiveis.Count == _slotsRecursos.Count;
    }

    void Start()
    {
        //Garante que será renderizado corretamente
        transform.SetAsLastSibling();

        //Cria a lista de recursos disponíveis com todas as opções possíveis
        _recursosDisponiveis = Enum.GetValues(typeof(Recursos)).Cast<int>().ToList();

        //Para cada recurso
        foreach(int val in _recursosDisponiveis)
        {
            //Instancia o prefab do recurso
            GameObject recurso = Instantiate(_prefabRecursos[val], _slotsRecursos[val]);
            recurso.GetComponent<Image>().color = Color.black;
        }
    }
}
