/*************************************************************************
> File Name: Parallel.h
> Project Name: CubbyFlow
> Author: Chan-Ho Chris Ohk
> Purpose: Parallel functions for CubbyFlow.
> Created Time: 2017/02/05
> Copyright (c) 2017, Chan-Ho Chris Ohk
*************************************************************************/
#ifndef CUBBYFLOW_PARALLEL_H
#define CUBBYFLOW_PARALLEL_H

namespace CubbyFlow
{
	//!
	//! \brief      Fills from \p begin to \p end with \p value in parallel.
	//!
	//! This function fills a container specified by begin and end iterators in
	//! parallel. The order of the filling is not guaranteed due to the nature of
	//! parallel execution.
	//!
	//! \param[in]  begin          The begin iterator of a container.
	//! \param[in]  end            The end iterator of a container.
	//! \param[in]  value          The value to fill a container.
	//!
	//! \tparam     RandomIterator Random iterator type.
	//! \tparam     T              Value type of a container.
	//!
	template <typename RandomIterator, typename T>
	void ParallelFill(const RandomIterator& begin, const RandomIterator& end, const T& value);

	//!
	//! \brief      Makes a for-loop from \p beginIndex \p to endIndex in parallel.
	//!
	//! This function makes a for-loop specified by begin and end indices in
	//! parallel. The order of the visit is not guaranteed due to the nature of
	//! parallel execution.
	//!
	//! \param[in]  beginIndex The begin index.
	//! \param[in]  endIndex   The end index.
	//! \param[in]  function   The function to call for each index.
	//!
	//! \tparam     IndexType  Index type.
	//! \tparam     Function   Function type.
	//!
	template <typename IndexType, typename Function>
	void ParallelFor(IndexType beginIndex, IndexType endIndex, const Function& function);

	//!
	//! \brief      Makes a 3D nested for-loop in parallel.
	//!
	//! This function makes a 3D nested for-loop specified by begin and end indices
	//! for each dimension. X will be the inner-most loop while Z is the outer-most.
	//! The order of the visit is not guaranteed due to the nature of parallel
	//! execution.
	//!
	//! \param[in]  beginIndexX The begin index in X dimension.
	//! \param[in]  endIndexX   The end index in X dimension.
	//! \param[in]  beginIndexY The begin index in Y dimension.
	//! \param[in]  endIndexY   The end index in Y dimension.
	//! \param[in]  beginIndexZ The begin index in Z dimension.
	//! \param[in]  endIndexZ   The end index in Z dimension.
	//! \param[in]  function    The function to call for each index (i, j, k).
	//!
	//! \tparam     IndexType   Index type.
	//! \tparam     Function    Function type.
	//!
	template <typename IndexType, typename Function>
	void ParallelFor(
		IndexType beginIndexX, IndexType endIndexX,
		IndexType beginIndexY, IndexType endIndexY,
		IndexType beginIndexZ, IndexType endIndexZ,
		const Function& function);

	//!
	//! \brief      Sorts a container in parallel.
	//!
	//! This function sorts a container specified by begin and end iterators.
	//!
	//! \param[in]  begin          The begin random access iterator.
	//! \param[in]  end            The end random access iterator.
	//!
	//! \tparam     RandomIterator Iterator type.
	//!
	template<typename RandomIterator>
	void ParallelSort(RandomIterator begin, RandomIterator end);

	//!
	//! \brief      Sorts a container in parallel with a custom compare function.
	//!
	//! This function sorts a container specified by begin and end iterators. It
	//! takes extra compare function which returns true if the first argument is
	//! less than the second argument.
	//!
	//! \param[in]  begin           The begin random access iterator.
	//! \param[in]  end             The end random access iterator.
	//! \param[in]  compare         The compare function.
	//!
	//! \tparam     RandomIterator  Iterator type.
	//! \tparam     CompareFunction Compare function type.
	//!
	template<typename RandomIterator, typename CompareFunction>
	void ParallelSort(RandomIterator begin, RandomIterator end, CompareFunction compare);
}

#endif